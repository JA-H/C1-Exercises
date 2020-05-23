#include<iostream>

int main( int argc, char *argv[] )
{
  const int N = 10;
  double *doubleArray;
  int *intArray;
  
  // allocate memory
  doubleArray = new double [ N ];
  intArray = new int[ N ];
  
  // set values in arrays
  for( int i = 0; i < N; ++i )
  {
    doubleArray[ i ] = 1.0;
    intArray[ i ] = 2;
  }
 
 // print double array
 std::cout << "printing doubleArray" << std::endl;
 for( int  i = 0; i < N; ++i )
 {
    std::cout << doubleArray[ i ] << std::endl;
 }
  
 // print int array
 std::cout << "printing intArray" << std::endl;
 for( int  i = 0; i < N; ++i )
 {
    std::cout << intArray[ i ] << std::endl;
 }
 
 return 0;
 
}