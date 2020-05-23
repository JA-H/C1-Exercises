#include<iostream>
#include<cmath>

const double pi = 3.14159;

//NEEDS REVIEWING

double F(double alpha, double m)
{
  const double h = (pi / (double)m);
  
  double I = 0;
  double x = 0;
  int n;
  
  for ( n = 0 ; n < m ; ++n )
  {
    x = x + h;
    
    I = I + std::sin(x);
  }
  
  return h*I;
}



int main()
{
    
  return 0;
}