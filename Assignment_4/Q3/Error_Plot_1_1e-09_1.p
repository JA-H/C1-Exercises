set terminal wxt
set title 'Error: Alpha = 1.0, Beta = 1.0e-9, L = 1.0'

set logscale x

set xlabel 'log-Number of Nodes'
set ylabel 'Error'

set xrange [4 : 512]
set yrange [0 : 1]


plot "Error_Plot_1_1e-09_1.dat" u 1:2 with lines title "Error", \

set term png
set output 'Error_Plot_1_1e-09_1.png'
replot
