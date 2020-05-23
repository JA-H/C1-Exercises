#ifndef BVP_HH
#define BVP_HH

#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <armadillo>

#include "ode.hh"
#include "bc.hh"
#include "fdg.hh"

typedef arma::vec vec;
typedef arma::sp_mat sMat;

class BVP
{
private:
  BVP(const BVP& otherBVP){}

  //Number of nodes
  int numNodes_;

  //Pointer to grid
  FiniteDifferenceGrid* pGrid_;

  //ODE Pointer
  ODE* pODE_;

  //Boundary Conditions Pointer
  BC* pBC_;

  //Solution vector pointer
  vec* pSolVec_;

  //RHS vector pointer
  vec* pRHSVec_;

  //Matrix for linear system (which is a sparse Matrix)
  sMat* pA_;

  //Output file name
  std::string Filename_;

  //Data input functions
  void PopulateMatrix();
  void PopulateVector();
  void ApplyBC();

public:
  //Constructor
  BVP( ODE* pODE, BC* pBC, int numNodes);

  //Destructor
  ~BVP();

  void SetFilename(const std::string& name)
  {
    Filename_ = name;
  }
  void Solve();
  void WriteSolution();
};

#endif
