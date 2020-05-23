set terminal wxt
set title 'Lambda vs. Iterations vs. Residual'
set xlabel 'Lambda'
set ylabel 'Number of Iterations'
set zlabel 'Residual Error'
set view 41, 146
splot "data.dat" u 2:3:4
set term png
set output 'lambda_iterations_residual.png'
replot