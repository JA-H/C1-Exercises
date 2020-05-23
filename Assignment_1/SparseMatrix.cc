// Implementation of SparseMatrix class.

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cassert>
#include<cstdlib>
#include<fstream>

#include "SparseMatrix.hh"
#include "VectorOperations.hh"

//Default Constructor
SparseMatrix::SparseMatrix()
{
}

//Constructor
SparseMatrix::SparseMatrix( unsigned int M, 
			    unsigned int N, 
			    std::vector< std::vector<double> > values, 
			    std::vector< std::vector<unsigned int> > column_position )
  : M_ ( M ), N_ ( N ), values_ ( values ), column_position_ ( column_position )
{
  values_.resize(M_);
  column_position_.resize(M_);
}

//Copy Constructor
SparseMatrix::SparseMatrix( const SparseMatrix& source )
  : M_ ( source.M_ ), N_ ( source.N_ ), values_ ( source.values_ ), column_position_ ( source.column_position_ )
{
}

//Destructor
SparseMatrix::~SparseMatrix()
{
}


/* The add_entry function takes the row and column positions and adds the value of the matrix at the position to the ith element
 * of the "values" vector and the column position to the ith element of the "comlumn_position" vector.
 */
void SparseMatrix::add_entry( unsigned int i, unsigned int j, double a_ij ) 
{ 
  
  bool inserted = 0;
    
  // We check the values of i and j are valid.
  if( ( i >= M_ || j >= N_ ) && ( i < 0 || j < 0 ) )
  {
    std::cout << "Invalid indices: " << i << " , " << j << std::endl;
  }
   
  if(a_ij != 0)
  {
    
    if( ( values_[i].empty() ) && ( column_position_[i].empty() ) )
    {
      if(a_ij != 0.0)
      {
	column_position_[i].push_back(j);
	values_[i].push_back(a_ij);
      }
    }
    else
    {
      std::vector<unsigned int>::iterator it;
      std::vector<double>::iterator it2 = values_[i].begin();
      
      for( it = column_position_[i].begin(); ((it != column_position_[i].end()) && it2 != values_[i].end() ); ++it )
      {
	if(j == *it )
	{
	  values_[i].erase(it2);
	  values_[i].insert(it2, a_ij);
	  inserted = 1;
	  break;
	}
  
	if(j < *it )
	{
	  column_position_[i].insert(it,j);
	  values_[i].insert(it2,a_ij);
	  inserted = 1;
	  break;
	}

	it2++;
      }
      
      if (!inserted)
      {
	values_[i].push_back(a_ij);
	column_position_[i].push_back(j);
      }      
    }
  }
}


double SparseMatrix::get_entry(unsigned int i, unsigned int j)
{  
  // We check the values of i and j are valid.
  if( (i >= M_ || j >= N_) && ( i < 0 || j < 0 ) )
  {
    std::cout << "Invalid indices." << std::endl;
  }
  
  double a_ij;

  if( values_[i].empty() )
  {
    return 0.0;
  }
  
  else
  {
    std::vector<double>::iterator it = values_[i].begin();
    
    bool got = 0;
    
    for( std::vector<unsigned int>::iterator it2 = column_position_[i].begin(); it2 != column_position_[i].end(); ++ it2)
    { 
      if( j == *it2 )
      {
	a_ij = *it;
	got = 1;
	break;
      }
      else
      {
	++it;
      }
    }
    
    if(got != 1)
    {
      a_ij = 0.0;
    }
    
  }
  
  return a_ij;
}

//This method prints the nonzero elements of the sparse matrix.
void SparseMatrix::printV()
{
  
  std::cout << "Nonzero Values: " << std::endl;
  for(int i = 0; i < M_; ++i)
  {
    std::vector<double>::iterator it;
    
    for(it = values_[i].begin(); it != values_[i].end(); ++it)
    {
      std::cout << *it << std::endl;
    }
  }
}

//This method prints the whole matrix including zero terms. 
void SparseMatrix::printDense()
{
  for( int i = 0; i < M_; ++i)
  {
    std::cout << "[ ";
    for( int j = 0; j < N_; ++j)
    {
      std::cout << " " << get_entry(i , j) << ", " ;
    }
    std::cout << " ]" << std::endl;
  }
}

//This method calculates Ax where x is the input vector and A is the sparse matrix.
std::vector<double> SparseMatrix::multiply( std::vector<double> x )
{
   std::vector<double> result;
   
   if( x.size() != M_ )
   {
     std::cout << "Incorrect vector dimension." << std::endl;
   }
   else
   {
      for(int i = 0; i < M_; ++i)
      {
         if( column_position_[i].size() == 0 )
         {
	    result.push_back(0.0);
         }
         else
         {
	    std::vector<double>::iterator it = values_[i].begin();
	    double sum = 0.0;

	    for(std::vector<unsigned int>::iterator it2 = column_position_[i].begin(); it2 != column_position_[i].end(); ++it2 )
	    {
	       sum += *it*x[ *it2 ];
	       ++it;
	    }
	    result.push_back(sum);
         }
      }
    }
    return result;
}

/*
  * This method implements the Gauss-Seidel method of inverting a matrix; we want to solve for x, the equation Ax = b. We require that the matrix A have 
  * nonzero diagonal entries and A is invertible (so M_ = N_). We also note that convergence is only sure when A is symmetric positive definite or A is 
  * strictly or irreducibly diagonally dominant.
  * 
  * To implement the algorithm, we first set a constant tolerance to check convergence and then loop until the residual error is less than the tolerance. 
  * To find the approximate value of each entry x[i], we first iterate through the column_position_[i] and values_[i] vectors and initialise sum = 0.0 
  * and a_ii = 0.0. We note a_ii will be changed to a nonzero entry before the algorithm completes as A must has nonzero diagonal entries for the algorithm to work. 
  * We then iterate through the entries of values_[i] and column_position[i] to obtain the non-zero entries of the matrix. We note that iterating through both 
  * vectors simultaneously allows us to access both the value and the column position of that value easily.
  * 
  */  
std::vector<double> SparseMatrix::GaussSeidel(const std::vector<double> b, std::vector<double> x, double delta, double lambda)
{
  //Include check that the matrix is invertible and has nonzero diagonal entries?
   
  //The counter variable increases by one for each iteration.
  unsigned int counter = 0;
 
  if( ( M_ != N_ ) || ( b.size() != M_ ) || ( x.size() != M_ ) )
  {
    std::cout << "Invalid inputs" << std::endl;
  }
   
  else
  {
    const double tol = 1.0e-6;
    const unsigned int max_iterations = 1000000;
     
    double residual_error;
    
    std::ofstream iterationFile;
    iterationFile.open("data.dat", std::ios::app );
     
    do
    {
	for(int i = 0; i < M_; ++i)
	{
	  double sum = 0.0;
	  
	  //Setting a_ii = 0.0 will cause an error to occur unless a_ii is changed during the algorithm. This ensures that the matrix has nonzero diagonal entries
	  //which is required for the Gauss Seidel algorithm.
	  double a_ii = 0.0;
	
	  std::vector<double>::iterator it = values_[i].begin();
	
	  for(std::vector<unsigned int>::iterator it2 = column_position_[i].begin(); it2 != column_position_[i].end(); ++it2)
	  {
	      if(*it2 == i)
	      {
		//Changes a_ii to a nonzero value if the matrix is valid.
		a_ii = *it;
	      }
	    
	      else
	      {
		//Updates the sum according to the Gauss Seidel algorithm.
		sum += *it*x[ *it2 ];
	      }
	    
	      ++it;
	  }
	  
	  x[i] = (b[i] - sum) / a_ii;
	}
	++counter;
	
	//Check the residual error by comparing Ax with b in the supremum norm.
	residual_error = sup_difference(b , SparseMatrix::multiply(x));
	
	//Writing data to iterationFile.dat
	iterationFile << delta << "	" << lambda << "	" << counter << "	" << residual_error << std::endl;
	

    }while( (counter < max_iterations) && (residual_error > tol ) );
    
    iterationFile.close();
      
    if(counter == max_iterations)
    {
      std::cout << "Maximum number of iterations reached." << std::endl;
      return x;
    }
    else
    {
      std::cout << "N = " << N_ << ", " << "delta = " << delta << " and lambda = " << lambda << std::endl; 
      std::cout << "Final number of iterations: " << counter << std::endl;
      std::cout << "Final residual error: " << residual_error << std::endl;
      return x;
    }
  }
}













