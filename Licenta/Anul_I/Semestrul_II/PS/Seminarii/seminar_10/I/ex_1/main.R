#!/usr/bin/env Rscript

t_conf_interval <- function (n, alfa, sample_mean, s) {
    se = s / sqrt(n)
    critical_t = qt(1 - alfa/2, n-1)
    a = sample_mean - critical_t * s / sqrt(n);
    b = sample_mean + critical_t * s / sqrt(n);
    interval = c(a, b)
    return(interval)

}

# n - nr de mebri
# s - deviatia stadard 
# se .... 

