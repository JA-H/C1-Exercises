set terminal wxt
set title '2D Comparison'

set logscale x 2
set logscale y 2

set xlabel 'log-Number of Samples'
set ylabel 'log-Relative Error'


plot 1/sqrt(x) with lines title "Estimated Relative Error", \
	 "Continuous_2.dat" u 1:2 with lines title "Continuous", \
	 "Gaussian_2.dat" u 1:2 with lines title "Gaussian", \
	 "Simplex_2.dat" u 1:2 with lines title "Simplex", \
	 "Discontinuous_2.dat" u 1:2 with lines title "Discontinuous"

set term png
set output '2D.png'
replot
