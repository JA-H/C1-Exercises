#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/odeint.hpp>

using namespace boost::numeric::odeint;

typedef std::vector<double> state_type;

void lorenz( state_type &x , state_type &dxdt , double t )
{
	//method of manufactured solutiosn with exact solution
	//t^2 + 20
	//t^2 + 30
	//t^2 + 10

	double beta = 8./3;
	double omega = 10;
	double rho = 28;

	double dqdt1 = 2*t;
	double dqdt2 = 2*t;
	double dqdt3 = 2*t;

	double fut1 = -beta*x[0]+x[1]*x[2];
	double fut2 = -omega*x[1]+omega*x[2];
	double fut3 = x[1]*(rho-x[0])-x[2];

	double q1 = (t*t+20);
	double q2 = (t*t+30);
	double q3 = (t*t+10);

	double qut1 = -beta*q1+q2*q3;
	double qut2 = -omega*q2+omega*q3;
	double qut3 = q2*(rho-q1)-q3;

	dxdt[0] = dqdt1 + fut1-qut1;
	dxdt[1] = dqdt2 + fut2-qut2;
	dxdt[2] = dqdt1 + fut3-qut3;

}

void runge_kutta_4(double tau, std::string filename)
{
	std::ofstream myfile;
	myfile.open(filename.c_str(), std::ofstream::app);

	runge_kutta4<state_type> rk4;
	//4th order runge kutta

	state_type x(3);
	double t = 0;

	x[0] = 20;
	x[1] = 30;
	x[2] = 10;

	while(t<10)
	{
    	rk4.do_step(lorenz,x,t,tau );

		double sol1 = x[0];
		double sol2 = x[1];
		double sol3 = x[2];

			double error1 = fabs((t*t+20)-x[0]);
		double error2 = fabs((t*t+30)-x[1]);
		double error3 = fabs((t*t+10)-x[2]);

		t+=tau;

		myfile << t << "\t" << std::max(std::max(error1,error2),error3) << "\n";
	}

	myfile.close();
}

void forward_euler(double tau, std::string filename)
{
	std::ofstream myfile;
	myfile.open(filename.c_str(), std::ofstream::app);

	euler<state_type> eu;
	//forward euler

	state_type x(3);
	double t = 0;


	x[0] = 20;
	x[1] = 30;
	x[2] = 10;

	while(t<10)
	{
    		eu.do_step(lorenz,x,t,tau );

		double sol1 = x[0];
		double sol2 = x[1];
		double sol3 = x[2];

		double error1 = fabs((t*t+20)-x[0]);
		double error2 = fabs((t*t+30)-x[1]);
		double error3 = fabs((t*t+10)-x[2]);

		t+=tau;

		myfile << t << "\t" << std::max(std::max(error1,error2),error3) << "\n";
	}

	myfile.close();
}

void modified_mid(double tau, std::string filename)
{
	std::ofstream myfile;
	myfile.open(filename.c_str(), std::ofstream::app);

	modified_midpoint<state_type> mm;
	//modified midpoint method

	state_type x(3);
	double t = 0;

	x[0] = 20;
	x[1] = 30;
	x[2] = 10;

	while(t<10)
	{
    		mm.do_step(lorenz,x,t,tau );

		double sol1 = x[0];
		double sol2 = x[1];
		double sol3 = x[2];

		double error1 = fabs((t*t+20)-x[0]);
		double error2 = fabs((t*t+30)-x[1]);
		double error3 = fabs((t*t+10)-x[2]);

		t+=tau;

		myfile << t << "\t" << std::max(std::max(error1,error2),error3) << "\n";
	}
	myfile.close();
}

int main(int argc, char **argv)
{
	const int schemenum = atoi( argv[1]);
	double tau = atof(argv[2]);
	std::string filename = argv[3];

	switch(schemenum)
	{
		case 1:
			forward_euler(tau,filename);
			break;
		case 2:
			runge_kutta_4(tau,filename);
			break;
		case 3:
			modified_mid(tau,filename);
			break;
		default:
			std::cout << "Entered a wrong value" << std::endl;
	}

return 0;
}
