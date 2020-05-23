set terminal wxt
set title 'Modified Midpoint Comparison'

set logscale y

set xlabel 'Time'
set ylabel 'log-Approximation Error'


plot "Modified_Mid_Tau_0.01.dat" u 1:2 with lines title "Tau = 0.01", \
	"Modified_Mid_Tau_0.005.dat" u 1:2 with lines title "Tau = 0.005", \
	"Modified_Mid_Tau_0.0025.dat" u 1:2 with lines title "Tau = 0.0025", \
	"Modified_Mid_Tau_0.00125.dat" u 1:2 with lines title "Tau = 0.00125", \

set term png
set output 'MM.png'
replot
