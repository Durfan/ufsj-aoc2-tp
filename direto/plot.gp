set title "Cache Simulator"
set xlabel "Cache Size"
set ylabel "Cache Hit"
set key right bottom
set xrange [0:100]
set yrange [0:100]
set y2range [0:100]
set autoscale y2
set grid ytics lc rgb "#bbbbbb" lw 1 lt 0
set grid xtics lc rgb "#bbbbbb" lw 1 lt 0
set xtics ("0" 0, "16" 16, "32" 32, "64" 64, "128" 128, "256" 256, "512" 512)

plot for [col=1:10:2] 'quicksort.dat' using col smooth bezier
