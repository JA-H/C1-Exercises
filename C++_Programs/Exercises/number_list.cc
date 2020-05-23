#include<iostream>

int main()
{
  int n;
  
  for( n = 20; n > 0; n-- )
  {
    if (n % 4 == 0 )
    {
      continue ;
    }
    
    std::cout << (20 - n) << std::endl;
    
    if (n == 5)
    {
      break;
    }
  }
  
  return 0;
}