#! /bin/bash

#COMPILATION
make q1_main

#RUN COMANDS
./q1_main 2 1
./q1_main 2 2
./q1_main 2 3
./q1_main 2 4
./q1_main 10 1
./q1_main 10 2
./q1_main 10 3
./q1_main 10 4

echo "load '2D.p'" | gnuplot -persist
echo "load '10D.p'" | gnuplot -persist
