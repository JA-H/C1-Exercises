#include<iostream>

class Point
{
  public:
    double getX();
    double getY();
    void setX( double val );
    void setY( double vval);
    double norm();
    
  private:
    double x_;
    double y_;
}

void Point::setX( double val )
{
  x_ = val;
}

void Point::setY( double val )
{
  y_ = val;
}

void Point::getX()
{
  return x_;
}

void Point::getY()
{
  return y_;
}

double Point::norm()
{
  return std::sqrt( x_ * x_ + y_ * y_ );
}


int main()
{
  return 0;
}




