set terminal wxt
set title 'Expectation of u(T)'

set logscale x 2
set auto y

set xlabel 'log-Number of Samples'
set ylabel 'Expectation'

plot "expectation.dat" u 1 : 3 with lines title "v(T)"

set term png
set output 'expectation_v.png'
replot
