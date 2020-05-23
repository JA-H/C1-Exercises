#ifndef SPARSECLASSHEADERDEF // This ensures the header file is included only once.
#define SPARSECLASSHEADERDEF

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cassert>
#include<cstdlib>
#include<fstream>

#include "VectorOperations.hh"

class SparseMatrix
{
  public:    
    //Default Constructor
    SparseMatrix();
    
    SparseMatrix( const unsigned int M, 
		  const unsigned int N, 
		  const std::vector< std::vector<double> > values, 
		  const std::vector< std::vector<unsigned int> > column_position );
    
    //Copy Constructor
    SparseMatrix( const SparseMatrix& source );
    
    
    //Destructor
    ~SparseMatrix();
    
    /* The add_entry method takes the row number, the column number and 
     * the value of the matrix at this position.
     */
    void add_entry( unsigned int i, unsigned int j, double a_ij);
    
    //Print nonzero values
    void printV();
    
    //Print dense form of matrix
    void printDense();
    
    //Getter for values of the matrix
    double get_entry(unsigned int i, unsigned int j);
    
    //Multiply by a vector
    std::vector<double> multiply( std::vector<double> x );
    
    //Gauss-Seidel method
    std::vector<double> GaussSeidel( const std::vector<double> b, std::vector<double> x, double delta, double lambda );
    
    
  private:
    unsigned int M_;	//Number of rows.
    unsigned int N_;	//Number of columns.
    std::vector< std::vector<double> > values_;
    std::vector< std::vector<unsigned int> > column_position_;
};

#endif 