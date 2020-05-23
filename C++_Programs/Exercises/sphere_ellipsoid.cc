#include<iostream>
#include<cmath>

const double pi = 3.14159;

const double pterm = 1.6075;

double calculateVolume ( double a, double b, double c )
{
  double V;
  V = (4.0/3.0)*pi*a*b*c;
  return V;
}

double calculateArea ( double a, double b, double c )
{
  
 double quoterm;
 quoterm = ((std::pow( a*b , pterm ) + std::pow( a*c, pterm ) + std::pow( b*c, pterm ) )/3);
 
 double A;
 A = 4.0*pi*std::pow( quoterm, (1/pterm) );
 return A;
}

int main()
{
  double a, b, c;
  std::cout << "What are the radii of the ellipsoid?: " << std::endl;
  std::cin >> a >> b >> c;
  
  double volume;
  volume = calculateVolume(a, b, c);
  
  double surface_area;
  surface_area = calculateArea(a, b, c);
  
  
  
  std::cout << "The volume of the ellipsoid is " << volume << " and the surface area of the ellipsoid is " << surface_area << "." << std::endl;
  
  return 0;
  
}