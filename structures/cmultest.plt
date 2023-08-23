set xrange [-2.0:2.0]
set yrange [-2.0:2.0]
set terminal pdf
set output 'cmultest.pdf'
set size square
plot 'cmultest.dat'
