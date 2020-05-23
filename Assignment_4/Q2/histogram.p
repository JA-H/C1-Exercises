clear
reset

set terminal wxt
set title 'v(T) for random values of mu'

set xrange [0 : 60000]
set auto y

set xlabel 'mu'
set ylabel 'v(T)'

set key off
set border 3

# Add a vertical dotted line at x=0 to show centre (mean) of distribution.
set yzeroaxis

# Each bar is half the (visual) width of its x-range.
set boxwidth 50.0 absolute
set style fill solid 100.0 noborder

bin_width = 2000.0;

bin_number(x) = floor(x/bin_width)

rounded(x) = bin_width * ( bin_number(x) + 0.5 )

plot 'histogram.dat' using (rounded($1)):(1) smooth frequency with boxes

set term png
set output 'histogram.png'
replot
