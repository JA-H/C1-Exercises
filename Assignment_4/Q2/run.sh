#! /bin/bash

#COMPILATION
make q2_main

#RUN COMMANDS
./q2_main 1	0.1
./q2_main 2	0.1
./q2_main 4	0.1
./q2_main 8	0.1
./q2_main 16 0.1
./q2_main 32 0.1
./q2_main 64 0.1
./q2_main 128	0.1
./q2_main 256	0.1
./q2_main 512	0.1
./q2_main 1024 0.1
./q2_main 2048 0.1
./q2_main 4096 0.1

#PLOT GRAPHS
echo "load 'histogram.p'" | gnuplot -persist
echo "load 'expectation_u.p'" | gnuplot -persist
echo "load 'expectation_v.p'" | gnuplot -persist
echo "load 'variance_u.p'" | gnuplot -persist
echo "load 'variance_v.p'" | gnuplot -persist

rm histogram.dat
rm expectation.dat
rm variance.dat
