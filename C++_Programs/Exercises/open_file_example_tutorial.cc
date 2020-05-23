#include<iostream>
#include<fstream>

using namespace std;

int main()
{
  ofstream myfile;
  myfile.open ("example.txt");
  myfile << "This is some text." << endl;
  myfile.close();
  return 0;
}