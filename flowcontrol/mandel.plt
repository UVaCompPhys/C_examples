# generate plot of Mandelbrot set
# usage in gnuplot: load "mandel.plt"
set xlabel "Re"
set ylabel "Im" -6
unset ztics
set view 0,0
splot [-2:0.5][-1.25:1.25][0:100] "mandel.dat" palette

# make a graphic file, then reset gnuplot
set term png
set output "mandel.png"
replot

# close the output file
set output
# reset gnuplot
reset
set term x11
