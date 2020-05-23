#include<iostream>
#include<ctime>
#include<cstdlib>



double myRand( double a, double b )
{
  return (double) a + ((double)rand() / (double)RAND_MAX)*(b - a); 
}

double average(double arg[], int length)
{
  for( int n=0; n < length; n++)
  {
    double sum;
    sum = sum + arg[n];
    double av = (sum / (double)length);
    return av;
  }
}

double min(double arg[], int length)
{
  double m;
  
  for( int n=0; n < length; n++)
  {
    m = arg[0];
    
    if(arg[n] < m)
    {
      m = arg[n];
    }
  }
  
  return m;
}

double max(double arg[], int length)
{
  double m;
  
  for( int n=0; n < length; n++)
  {
    m = arg[0];
    
    if(arg[n] >= m)
    {
      m = arg[n];
    }
  }
  
  return m;
}

int main()
{
  srand( time( NULL ) );
  
  double rand_array[100];

  for (int i = 0; i < 100; ++i)
  {
    rand_array[ i ] = myRand(-50.0 , 50.0);
  }
  
  std::cout << "Average: " << average(rand_array, 100) <<std::endl;
  
  std::cout << "Minimum: " << min(rand_array, 100) <<std::endl;
  
  std::cout << "Maximum: " << max(rand_array, 100) <<std::endl;
  
  return 0;
}