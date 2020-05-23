/*
 * file: main.cc
 *
 * example of how to use the point class
 */

#include <iostream>
#include "point.hh"

int main() 
{
  // print number of instance of class at start
  Point::printInstances();

  // create an instance using setters and getters
  Point a;
  a.setX(1.1);
  a.setY(2.2);
  a.printInstances();

  // create an instance using the assignment operator
  Point c;
  c = a;
  std::cout << "(" << c.getX() << ", " << c.getY() << ")" << std::endl;

  // use a clever constructor
  Point b(3.2, 5.6);
  std::cout << "Distance from origin: " << c.distance() << std::endl;

  // check comparison operators
  if (c < b) 
    {
      Point d = c;
      d = d;
      std::cout << "C is nearer to the origin than B" << std::endl;
      d.printInstances();
    }
  else 
    {
      std::cout << "C is further from the origin than B" << std::endl;
    }
  std::cout << "D has now gone out of scope and been destroyed" << std::endl;

  // print number of instances at end
  c.printInstances();

  return 0;
}
