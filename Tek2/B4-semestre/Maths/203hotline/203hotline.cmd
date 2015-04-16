set title "author: somasu_b, potier_g\n203hotline"
set palette  define (0 "red", 1 "blue", 2 "yellow", 3 "green");
set style fill solid 0.25 border -1 
set boxwidth 0.4 relative
plot './data/poisson.test' using ($1-0.2):2 with boxes title 'Loi Poisson', './data/binomial.test' using ($1+0.2):2 with boxes title 'Loi Binomial'
pause -1