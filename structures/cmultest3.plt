set size square
set xrange [-2.0:2.0]
set yrange [-2.0:2.0]
set terminal pdf
set output 'cmultest3.pdf'
plot 'cmultest_r0.99.dat','cmultest_r1.00.dat','cmultest_r1.01.dat' 
