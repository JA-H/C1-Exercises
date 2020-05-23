// C1 Assignment 1.

#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cassert>
#include<cstdlib>
#include<fstream>

#include "SparseMatrix.hh"
#include "VectorOperations.hh"


int main( int argc, char* argv[] )
{ 
  //Testing the implementation of Gauss-Seidel
  
  //Set the size of the N by N matrix A = (a_ij)
  unsigned int N = atoi(argv[1]); 	//N = 100, 1000, 10000
  
  
  //Define the constants delta and a
  double delta = atof(argv[2]); 		// delta > 0
  double lambda = atof(argv[3]);		// lambda > 0
  
  assert((delta > 0)&&(lambda >=0));
  
  double a = 4.0*(1.0 - delta);
  
  
  //Define vector w
  std::vector<double> w;
  
  for(int i = 0; i < N; ++i )
  {
    double w_i = ( (double)i + 1.0 )/( (double)N + 1.0 );
    w.push_back(w_i);
  }
  
  
  //Define vector b
  std::vector<double> b;
  
  for(int i = 0; i < N - 1; ++i)
  { 
    double b_i = -2.0*a*(w[i] - (1.0/2.0) )*w[0]*w[0];
    b.push_back(b_i);
  }
  double b_Nn1 = -2.0*a*( w[N-1] - (1.0/2.0) )*w[0]*w[0] + 1.0; 
  b.push_back(b_Nn1);
  
  
  //Define initial guess vector x_0
  std::vector<double> x_0;
  for(int i = 0; i < N; ++i)
  {
    x_0.push_back(0.0);
  }
  
  
  //Define D = (D_-1, D_0, .... , D_N-1) which are used in the definition of A = (a_ij)
  std::vector<double>::iterator it_w = w.begin();	//We require this iterator as the entries D_i are defined in terms of the entries of w
  std::vector<double> D;
    
  double D_n1 = a*(*it_w - 1.0/2.0)*(*it_w - 1.0/2.0) + delta;
  D.push_back(D_n1);
  for(it_w = w.begin(); it_w != w.end(); ++ it_w)
  {
    double D_i = a*( *it_w - 1.0/2.0 )*( *it_w - 1.0/2.0 ) + delta;
    D.push_back(D_i);
  }
  
  
  //Define the spare matrix A = (a_ij)
  std::vector< std::vector<unsigned int> > TriDiag_col;
  std::vector< std::vector<double> > TriDiag_values;
  
  SparseMatrix TriDiag(N, N, TriDiag_values, TriDiag_col);
  
  TriDiag.add_entry(0, 0, D[1] + D[0] + lambda );
  TriDiag.add_entry(0, 1, -D[1] );
  TriDiag.add_entry(N - 1, N - 2, -D[N - 1] );
  TriDiag.add_entry(N - 1, N - 1, D[N]+ D[N - 1] + lambda );
  
  for(int i = 1; i < N - 1; ++i)
  {
    TriDiag.add_entry(i, i - 1, -D[i] );
    TriDiag.add_entry(i, i, D[i] + D[i + 1] + lambda );
    TriDiag.add_entry(i, i + 1, -D[i + 1]);
  }
 
  
  //Apply the methods defined in the SparseMatrix class
  std::vector<double> x_k = TriDiag.GaussSeidel(b, x_0 , delta, lambda);
  std::vector<double> A_x = TriDiag.multiply(x_k);
  
  
  
  if((lambda == 0) && (delta == 1.0))
  {
    //As we know the real solution to Ax = b when delta = 1 and lambda = 0 is x = w, we can check the error of the Gauss-Seidel method in the L^infinity norm. 
    double error = sup_difference(x_k, w);
    std::cout << "Final Error: " << error << std::endl;
  }
  
  
  return 0;
}