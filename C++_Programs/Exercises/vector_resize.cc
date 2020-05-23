#include<iostream>
#include<vector>
#include<cstdlib>

int main()
{
  // Resizing vectors
  int M, N;
  std::vector< double > myVector;
  M = myVector.size();
  myVector.resize(N);

  //Iterating over a vector
  std::vector< unsigned int > randVec( 10 );
  std::vector< unsigned int >::iterator it;
  
  const std::vector< unsigned int >::iterator end = randVec.end();
  
  for( it = randVec.begin() ; it != end ; ++it )
  {
    *it = rand();
  }
  
  
  
  return 0;
}