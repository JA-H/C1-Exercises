#! /bin/bash

#COMPILATION
make Assignment_2

#RUN COMMANDS
./Assignment_2 1 1 0.1 12
./Assignment_2 2 1 0.1 12
./Assignment_2 1 2 0.1 12
./Assignment_2 2 2 0.1 12
./Assignment_2 1 3 0.1 12
./Assignment_2 2 3 0.1 12
./Assignment_2 1 4 0.1 12
./Assignment_2 2 4 0.1 12
./Assignment_2 1 5 0.1 12
./Assignment_2 2 5 0.1 12

echo "load 'FE.p'" | gnuplot -persist
echo "load 'BE.p'" | gnuplot -persist
echo "load 'CN.p'" | gnuplot -persist
echo "load 'Heun3.p'" | gnuplot -persist
echo "load '2DIRK.p'" | gnuplot -persist


#pdflatex report.tex
