#include<iostream>

int fibonacci(int n)
{
  if (n < 0)
  {
    std::cout << "n must be greater than 0."
	      << std::endl;
	      
    return -1;
  }
  
  else if ((n == 0) ||( n == 1))
  {
    return 1; 
  }
  
  else
  {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

int main()
{
  int a;
  
  std::cout << "Name a positive integer: " << std::endl;
  std::cin >> a;
  
  int f;
  f = fibonacci(a);
  
  std::cout << "The nth Fibonacci number is " << f << std::endl;
  
  return 0;
  
}

