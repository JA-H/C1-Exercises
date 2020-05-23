/*
 * file: point.hh
 */

#ifndef CLASS_POINT
#define CLASS_POINT

#include <iostream>
#include <cmath>

/* 
 * class: Point
 * 
 * a class to hold a point in two dimensions  
 */
class Point {
public:
  Point();                       // Default constructor
  Point(double x, double y);
  Point(const Point& source);      // Copy constructor
  ~Point();                      // Destructor

  bool operator==(const Point& source);
  bool operator!=(const Point& source);
  bool operator==(const double value);
  bool operator!=(const double value);

  bool operator<(const Point& source);
  bool operator<=(const Point& source);
  bool operator>(const Point& source);
  bool operator>=(const Point& source);
        
  bool operator<(const double value);
  bool operator<=(const double value);
  bool operator>(const double value);
  bool operator>=(const double value);

  Point& operator=(const Point& source);
  Point operator+(const Point& source);
  Point operator-(const Point& source);

  double getX();                 // "Getter" and "setter" member functions
  double getY();
  void setX(double value);
  void setY(double value);
  
  double distance() const;       // Other member function
  
  static void printInstances();

private:
  double x_;                     // Private data
  double y_;

  static unsigned int instanceCount_;
};

#endif
