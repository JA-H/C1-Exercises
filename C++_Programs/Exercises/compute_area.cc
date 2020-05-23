#include<iostream>

const double pi = 3.14159;

double volume( double& radius)
{
  double V;
  V = (4.0/3.0)*pi*radius*radius*radius;
  return V;
}

double surface_area( double& radius )
{
  double S;
  S = 4.0*pi*radius*radius;
  return S;
}

int main()
{   
    double myRadius;
    
    std::cout << "What is the radius of your sphere?:" << std::endl;
    std::cin >> myRadius;
    
    double vol;
    vol = volume(myRadius);
    
    double s_a;
    s_a = surface_area(myRadius);
    
    std::cout << "The volume of the sphere is " << vol << " and the surface area of the sphere is " << s_a << "." << std::endl;
    
    return 0;
    
}