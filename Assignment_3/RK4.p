set terminal wxt
set title 'Runge-Kutta 4 Comparison'

set xlabel 'Time'
set ylabel 'Approximation Error'


plot "Runge_Kutta_4_Tau_0.01.dat" u 1:2 with lines title "Tau = 0.01", \
	 "Runge_Kutta_4_Tau_0.005.dat" u 1:2 with lines title "Tau = 0.005", \
	 "Runge_Kutta_4_Tau_0.0025.dat" u 1:2 with lines title "Tau = 0.0025", \
	 "Runge_Kutta_4_Tau_0.00125.dat" u 1:2 with lines title "Tau = 0.00125", \

set term png
set output 'RK4.png'
replot
