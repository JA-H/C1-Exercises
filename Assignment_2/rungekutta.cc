#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <sstream>

#include "schemes.hh"
#include "models.hh"

double solve(const ModelInterface* model, const DIRK* scheme, double tau, int modelNumber, int schemeNumber)
{
  double maxError = 0.0;
  double y=model->y0();
  double t = 0.0;
  
  std::ofstream myFile;
  if (tau == 0.1 || tau == 0.05)
  {
    std::string filename;
    std::stringstream convertScheme, convertTau, convertModel;
    convertScheme << schemeNumber;
    convertTau << tau;
    convertModel << modelNumber;
    filename = "Model_" + convertModel.str() + "_DIRK_" + convertScheme.str() + "_Tau_" + convertTau.str() + ".dat";
    myFile.open(filename.c_str(), std::ofstream::app);
  }
  
  while ( t<=model->T() )
  {
    y =  scheme->evolve(y,t,tau,model);
    t += tau;
    double error = y;
    error -= model->exact(t);
    if (tau == 0.1 || tau == 0.05)
    {
      myFile << t << "    " << log(fabs(error)) << "    "  << modelNumber << "    " << schemeNumber << "\n";
    }
    maxError = std::max(maxError,std::abs(error));
  }
  myFile.close();
  return maxError;
}

int main ( int argc, char *argv[] ) // called as ./rungekutta modelNumber schemeNumber tau level
{
  
  if (argc<5) // checks to see if enough arguments are inputted
  {
    std::cerr << "Error: Call " << argv[0] << " Model Scheme Tau_0 J" << std::endl; // error message
    return 1;
  }
  
  const int modelNumber = atoi( argv[1] );    // Model
  const int schemeNumber = atoi( argv[2] );   // DIRK Scheme
  double tau = atof( argv[3] );               // Initial time step
  const int level = atoi( argv[4] );          // Number of time steps
  
  ModelInterface* model;
  DIRK* scheme;
  
  //Choose which model to use depending on the value of argv[1].
  if (modelNumber == 1)
  {
    model = new Equation_1;
  }
  else if(modelNumber == 2)
  {
    model = new Equation_2;
  }
  else
  {
    std::cerr << "Error: choose either model 1 or 2." << std::endl;
    return 1;
  }
  
  //Choose which model to use depending on the value of argv[2].
  if (schemeNumber == 1)
  {
    std::cout << std::endl;
    std::cout << "Method: Forward Euler" << std::endl;
    std::cout << "Equation " << modelNumber << ":" << std::endl;
    std::cout << std::endl;
    scheme = new FE(1); // Forward Euler
  }
  else if (schemeNumber == 2)
  {
    std::cout << std::endl;
    std::cout << "Method: Backward Euler" << std::endl;
    std::cout << "Equation " << modelNumber << ":" << std::endl;
    std::cout << std::endl;
    scheme = new BE(1); // Backward Euler
  }
  else if (schemeNumber == 3)
  {
    std::cout << std::endl;
    std::cout << "Method: Crank Nicholson" << std::endl;  
    std::cout << "Equation " << modelNumber << ":" << std::endl;
    std::cout << std::endl;
    scheme = new CN(1); // Crank Nicholson
  }
  else if (schemeNumber == 4)
  {
    std::cout << std::endl;
    std::cout << "Method: 3-Stage Heun" << std::endl; 
    std::cout << "Equation " << modelNumber << ":" << std::endl;
    std::cout << std::endl;
    scheme = new Heun3(3); // 3-stage Heun
  }
  else if (schemeNumber == 5)
  {
    std::cout << std::endl;
    std::cout << "Method: 2-stage DIRK" <<std::endl; 
    std::cout << "Equation " << modelNumber << ":" << std::endl;
    std::cout << std::endl;
    scheme = new DIRK2(2); // 2-stage DIRK
  }
  else
  {
    std::cerr << "Error: scheme number must be between 1 and 5" << std::endl;
    return 1;
  }
  
  std::vector<double> maxErrorVector(level);
  double eoc = 0.0;
  std::cout.width(20);
  std::cout << "tau";
  std::cout.width(15);
  std::cout << "maxError";
  std::cout.width(15);
  std::cout << "eoc" << std::endl;
  for (int i=0;i<level;++i,tau/=2)
  {
    maxErrorVector[i] = solve(model, scheme, tau, modelNumber, schemeNumber);
    std::cout.width(20);
    std::cout << tau;
    std::cout.width(15);
    std::cout << maxErrorVector[i];
    if (i != 0)
    {
      eoc = log(maxErrorVector[i] / maxErrorVector[i-1])/log(0.5);
      std::cout.width(15);
      std::cout << eoc << std::endl;
    }
    else
    {
      std::cout << " " << std::endl;
    }
  }
  
  delete model;
  
  return 0;
}
