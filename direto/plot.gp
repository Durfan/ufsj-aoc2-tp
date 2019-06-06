#!/usr/bin/gnuplot

set term svg
set output "quicksort.svg"

set title "Cache Simulator"
set xlabel "Palavras por Bloco"
set ylabel "Cache Hit"

set xrange [0:33]
set autoscale y

set xtics ("1" 1, "2" 2, "4" 4, "8" 8, "16" 16, "32" 32)
set grid ytics lc rgb "#bbbbbb" lw 1 lt 0
set grid xtics lc rgb "#bbbbbb" lw 1 lt 0

set key autotitle columnheader bottom right

plot for [i=0:5] 'quicksort.dat' u 1:2 index i t columnhead(1) smooth bezier
