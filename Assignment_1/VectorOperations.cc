//Vector Operations cc file

#include "VectorOperations.hh"

double norm_infinity( std::vector<double> x )
{
  double result;
  
  if( x.size() == 0)
  {
    result = 0.0;
  }
  
  else
  {
    result = std::fabs( x[0] );
  
    for(std::vector<double>::iterator it = x.begin(); it != x.end(); ++it)
    {
      if( result < std::fabs( *it ))
      {
	result = std::fabs( *it );
      }
    }
  }
  return result; 
}

double sup_difference(std::vector<double> x, std::vector<double> y)
{
  double sup_diff = 0.0;
  
  if( x.size() != y.size() )
  {
    std::cout << "Incorrect vector dimensions" << std::endl;
  }
  else
  {
    for(int i = 0; i < x.size(); ++i)
    {
      if( sup_diff < std::fabs(x[i] - y[i]) )
      {
	sup_diff = std::fabs(x[i] - y[i] );
      }
    }
  }
  
  return sup_diff;
}