#! /bin/bash

#COMPILATION
make main

#RUN COMMANDS
./main 1 0.001 Forward_Euler_Tau_0.001.dat
./main 1 0.0005 Forward_Euler_Tau_0.0005.dat
./main 1 0.00025 Forward_Euler_Tau_0.00025.dat
./main 1 0.000125 Forward_Euler_Tau_0.000125.dat

./main 2 0.01 Runge_Kutta_4_Tau_0.01.dat
./main 2 0.005 Runge_Kutta_4_Tau_0.005.dat
./main 2 0.0025 Runge_Kutta_4_Tau_0.0025.dat
./main 2 0.00125 Runge_Kutta_4_Tau_0.00125.dat

./main 3 0.01 Modified_Mid_Tau_0.01.dat
./main 3 0.005 Modified_Mid_Tau_0.005.dat
./main 3 0.0025 Modified_Mid_Tau_0.0025.dat
./main 3 0.00125 Modified_Mid_Tau_0.00125.dat


echo "load 'FE.p'" | gnuplot -persist
echo "load 'RK4.p'" | gnuplot -persist
echo "load 'MM.p'" | gnuplot -persist







#Delete Data Files
rm Forward_Euler_Tau_0.001.dat
rm Forward_Euler_Tau_0.0005.dat
rm Forward_Euler_Tau_0.00025.dat
rm Forward_Euler_Tau_0.000125.dat

rm Runge_Kutta_4_Tau_0.01.dat
rm Runge_Kutta_4_Tau_0.005.dat
rm Runge_Kutta_4_Tau_0.0025.dat
rm Runge_Kutta_4_Tau_0.00125.dat

rm Modified_Mid_Tau_0.01.dat
rm Modified_Mid_Tau_0.005.dat
rm Modified_Mid_Tau_0.0025.dat
rm Modified_Mid_Tau_0.00125.dat



#pdflatex report.tex
