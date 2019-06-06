set key right bottom
set xrange [0:528]
set yrange [0:100]
set xtics ("0" 0, "16" 16, "32" 32, "64" 64, "128" 128, "256" 256, "512" 512)

plot "quicksort.dat" using 1:8 title 'Quicksort 8w/bloco' with lines,\
     "selection.dat" using 1:8 title 'Selection 8w/bloco' with lines,\
     "bubblesort.dat" using 1:8 title 'BubbleSort 8w/bloco' with lines
