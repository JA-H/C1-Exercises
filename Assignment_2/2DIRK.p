set terminal wxt
set title '2-stage DIRK Comparison'

set xlabel 'Time'
set ylabel 'log-Approximation Error'




plot "Model_1_DIRK_5_Tau_0.1.dat" u 1:2 with lines title "Model 1, Tau = 0.1", \
	 "Model_1_DIRK_5_Tau_0.05.dat" u 1:2 with lines title "Model 1, Tau = 0.05", \
	 "Model_2_DIRK_5_Tau_0.1.dat" u 1:2 with lines title "Model 2, Tau = 0.1", \
	 "Model_2_DIRK_5_Tau_0.05.dat" u 1:2 with lines title "Model 2, Tau = 0.05", \

set term png
set output '2DIRK.png'
replot