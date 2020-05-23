/*
 * file: point.hh
 *
 * implementation of Point class
 */

#include "point.hh"

// Initialise static members
unsigned int Point::instanceCount_=0;

// Default constructor: just initialise to zero.
Point::Point() 
  : x_( 0.0 ), y_( 0.0 ) 
{
  ++instanceCount_;
}

// Set position of point on construction.
Point::Point( double x, double y ) 
  : x_ ( x ), y_( y ) 
{
  ++instanceCount_;
}

// Copy constructor
Point::Point(const Point& source ) 
  : x_( source.x_ ), y_ ( source.y_ )
{
  ++instanceCount_;
}

// Destructor
Point::~Point() {
  --instanceCount_;
}

bool Point::operator==( const Point& source ) 
{
  return ( x_ == source.x_ && y_ == source.y_ );
}

bool Point::operator==(const double value) {
  return (distance() == value);
}

bool Point::operator!=(const Point& source) {
  return !operator==(source);
}

bool Point::operator!=(const double value) {
  return !operator==(value);
}

bool Point::operator<(const Point& source) {
  return operator<(source.distance());
}

bool Point::operator<=(const Point& source) {
  return (operator<(source) || operator==(source.distance()));
}

bool Point::operator>(const Point& source) {
  return operator>(source.distance());
}

bool Point::operator>=(const Point& source) {
  return (operator>(source) || operator==(source.distance()));
}
        
bool Point::operator<(const double value) {
  return (distance() < value);
}

bool Point::operator<=(const double value) {
  return (operator<(value) || operator==(value));
}

bool Point::operator>(const double value) {
  return (distance() > value);
}

bool Point::operator>=(const double value) {
  return (operator>(value) || operator==(value));
}

Point& Point::operator=(const Point& source) {
  if (this == &source) {
    std::cout << "Ignoring self-assignment" << std::endl;
    return *this;
  }
  x_ = source.x_;
  y_ = source.y_;
  return *this;
}

Point Point::operator+(const Point& source) {
  return Point(x_ + source.x_, y_ + source.y_);
}

Point Point::operator-(const Point& source) {
  return Point(x_ - source.x_, y_ - source.y_);
}

double Point::getX() {
  return x_;
}

double Point::getY() {
  return y_;
}

void Point::setX(double value) {
  x_ = value;
}

void Point::setY(double value) {
  y_ = value;
}

double Point::distance() const {
  return sqrt(x_*x_ + y_*y_);
}

void Point::printInstances() {
  std::cout << "There are " << instanceCount_ << " points." << std::endl;
}
