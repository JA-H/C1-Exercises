#ifndef BC_HH
#define BC_HH

class BC
{
public:
  friend class BVP;
private:
  double u_0_;
  double u_L_;
public:
  BC(){};
  void Set_u_0(double u_0)
  {
    u_0_ = u_0;
  }
  void Set_u_L(double u_L)
  {
    u_L_ = u_L;
  }
};






#endif
