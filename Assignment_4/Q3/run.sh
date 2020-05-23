#! /bin/bash

#COMPILATION
make q3_main

#RUN COMMANDS
./q3_main 1.0 1.0e-10 1.0 100
./q3_main 1.0 2.0 1.0 100
./q3_main 1.0 1000.0 1.0 100


#PLOTTING
echo "load '1_1e-09_1_100.p'" | gnuplot -persist
echo "load '1_2_1_100.p'" | gnuplot -persist
echo "load '1_1000_1_100.p'" | gnuplot -persist

echo "load 'Error_Plot_1_1e-09_1.p'" | gnuplot -persist
echo "load 'Error_Plot_1_2_1.p'" | gnuplot -persist
echo "load 'Error_Plot_1_1000_1.p'" | gnuplot -persist
