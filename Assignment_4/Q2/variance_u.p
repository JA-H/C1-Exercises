set terminal wxt
set title 'Variance of u(T)'

set logscale x 2
set auto y

set xlabel 'log-Number of Samples'
set ylabel 'Variance'

plot "variance.dat" u 1 : 2 with lines title "u(T)"

set term png
set output 'variance_u.png'
replot
