set terminal wxt
set title 'Forward Euler Comparison'

set logscale y
set yrange [0.000001 : 1e25]

set xlabel 'Time'
set ylabel 'log-Approximation Error'


plot "Forward_Euler_Tau_0.001.dat" u 1:2 with lines title "Tau = 0.001", \
	 "Forward_Euler_Tau_0.0005.dat" u 1:2 with lines title "Tau = 0.0005", \
	 "Forward_Euler_Tau_0.00025.dat" u 1:2 with lines title "Tau = 0.00025", \
	 "Forward_Euler_Tau_0.000125.dat" u 1:2 with lines title "Tau = 0.000125", \

set term png
set output 'FE.png'
replot
