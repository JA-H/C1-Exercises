set terminal wxt
set title 'Error: Alpha = 1.0, Beta = 1000.0, L = 1.0'

set logscale x

set xlabel 'log-Number of Nodes'
set ylabel 'Error'

set xrange [4 : 512]
set yrange [0 : 1]


plot "Error_Plot_1_1000_1.dat" u 1:2 with lines title "Error", \

set term png
set output 'Error_Plot_1_1000_1.png'
replot
