set terminal wxt
set title 'Delta vs. Iterations vs. Residual'
set xlabel 'Delta'
set ylabel 'Number of Iterations'
set zlabel 'Residual Error'
set view 41, 146
splot "data.dat" u 1:3:4
set term png
set output 'delta_iterations_residual.png'
replot