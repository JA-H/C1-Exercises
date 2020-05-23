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

#include "bvp.hh"

int main( int argc, char *argv[] )
{
  BC bdry;
  bdry.Set_u_0(0.0);
  bdry.Set_u_L(1.0);

  return 0;
}
