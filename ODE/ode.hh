#ifndef SECONDORDERODE_HH
#define SECONDORDERODE_HH

class ODE
{
  // A class storing the ODE -alpha u'' + beta u ' = 0 ON [0, L] with u(0) = 0 and u(L) = 1.
  friend class BVP;
private:
  //Coefficients
  double alpha_;
  double beta_;

  //Interval length
  double L_;

public:
  ODE(double alpha, double beta, double L)
  {
    alpha_ = alpha;
    beta_ = beta;
    L_ = L;
  }
};

#endif
