set terminal wxt
set title 'Alpha = 1.0, Beta = 2.0, L = 1.0, Number of Nodes = 100'


set xlabel 'x'
set ylabel 'u(x)'

set xrange [0 : 1]
set yrange [-1 : 1]


plot "1_2_1_100.dat" u 1:2 with lines title "Approximate Solution", \
  "1_2_1_100.dat" u 1:3 with lines title "Exact Solution", \


set term png
set output '1_2_1_100.png'
replot
