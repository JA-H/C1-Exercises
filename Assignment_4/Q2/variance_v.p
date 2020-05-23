set terminal wxt
set title 'Variance of v(T)'

set logscale x 2
set auto y

set xlabel 'log-Number of Samples'
set ylabel 'Variance'

plot "variance.dat" u 1 : 3 with lines title "v(T)"

set term png
set output 'variance_v.png'
replot
