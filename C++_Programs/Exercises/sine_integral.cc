#include<iostream>
#include<cmath>

const double pi = 3.14159;

double sine_integral(int m)
{
  // NEED TO CONVERT N TO DOUBLE
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
  int it;
  
  std::cout << "How many iterations do you want: " << std::endl;
  std::cin >> it; 
  
  std::cout << "The approximation is equal to " << sine_integral(it) << std::endl;
    
  return 0;
}