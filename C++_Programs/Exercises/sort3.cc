#include<iostream>

void swap(int& a, int& b)
{
  int temp = a;
  a = b;
  b = temp;
}

int main()
{
  int length;
  
  std::cout << "How many numbers do you want to sort?: " << std::endl;
  std::cin >> length;
  
  int *array = new int[length];
  
  for(int i = 0; i < length; i++)
  {
    std::cout << "Input element number " << i + 1 << ": ";
    std::cin >> array[i];
  }
  
  bool swapped = false;
  
  while(swapped == false)
  {  
    for(int i=1; i < length; i++)
    {
      if(array[i - 1] > array[i])
      {
	swap(array[i -1], array[i]);
	swapped = true;
      }
    }
  }
  
  for(int i = 0; i < length; i++)
  {
    std::cout << array[i] << ", ";
  }
  
  delete[] array;
  
  return 0;
}