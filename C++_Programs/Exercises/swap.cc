#include<iostream>

void swap(int& a, int& b)
{
  int temp = a;
  a = b;
  b = temp;
}

int main()
{
  int x, y;
  
  std::cout << "Name two integers: " << std::endl;
  std::cin >> x >> y;

  swap(x, y);

  std::cout << "a = " << x << " b = " << y << std::endl;

  return 0;
}