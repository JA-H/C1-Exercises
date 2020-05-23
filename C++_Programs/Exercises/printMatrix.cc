#include<iostream>

double printMatrix(const int row, const int column,const double array[])
{
  
}

void matrixVectorMultiply( const int M, const int N, const double A[], const double X[], double B[] )
{
  double 
  
  for(int i = 0; i < M; ++ i )
  {
    for(int j = 0; j < N; ++ j )
    {
      // B[ i * N + j ] = ;
    }
  }
}




int main()
{
  const int N = 50;
  
  double *matrix = new double[ N * N ];
  
  for(int i = 0; i < N; ++ i )
  {
    for(int j = 0; j < N; ++ j )
    {
      matrix[ i * N + j ] = i + j;
    }
  }
  
  return 0;
}