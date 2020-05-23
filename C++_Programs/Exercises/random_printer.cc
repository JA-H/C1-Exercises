#include<iostream>
#include<cstdlib>

int main()
{
  srand(time(NULL));
  std::cout << rand() << std::endl;

  return 0;
}