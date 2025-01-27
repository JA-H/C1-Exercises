#! /bin/bash

#COMPILATION
rm data.dat

make Assignment_1

#RUN COMMANDS

#In the first set of run commands we test the algorithm by setting delta = 1 and considering the time for N = 100, 1000, and 10000. 
time ./Assignment_1 100 1.0 0.0
time ./Assignment_1 1000 1.0 0.0
time ./Assignment_1 10000 1.0 0.0

rm "data.dat"


#In the second set of run commands we vary delta and keep lambda and N fixed.
#The parameters are N | delta | lambda
time ./Assignment_1 10 0.25 0.0
time ./Assignment_1 10 0.5 0.0
time ./Assignment_1 10 0.75 0.0
time ./Assignment_1 10 1.0 0.0
time ./Assignment_1 10 1.25 0.0
time ./Assignment_1 10 1.5 0.0


echo "load 'Delta_Iterations_Residual.p'" | gnuplot -persist
rm "data.dat"


#In the third set of run commands, we vary lamda and see the effect it has on the number of iterations.
time ./Assignment_1 10 1.0 0.00
time ./Assignment_1 10 1.0 0.01
time ./Assignment_1 10 1.0 0.02
time ./Assignment_1 10 1.0 0.03
time ./Assignment_1 10 1.0 0.04
time ./Assignment_1 10 1.0 0.05
time ./Assignment_1 10 1.0 0.06
time ./Assignment_1 10 1.0 0.07
time ./Assignment_1 10 1.0 0.08
time ./Assignment_1 10 1.0 0.09
time ./Assignment_1 10 1.0 0.1

echo "load 'Lambda_Iterations_Residual.p'" | gnuplot -persist
rm "data.dat"

