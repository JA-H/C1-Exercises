#ifndef FINITEDIFFERENCEGRID_HH
#define FINITEDIFFERENCEGRID_HH

#include <armadillo>
#include "node.hh"

class FiniteDifferenceGrid
{
public:
  friend class BVP;
private:
  arma::vec nodes_;
public:
  FiniteDifferenceGrid( int numNodes, double L )
  {
    for(int i = 0; i < numNodes; ++i)
    {
      double element = ((double) i / (double) numNodes)*L;
      //CHECK THIS NOTATION
      nodes_ << element << arma::endr;
    }
  }
};

#endif
