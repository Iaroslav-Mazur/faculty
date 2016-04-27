#!/usr/bin/env Rscript

# n - nr de sample
# range de siguranta
# media esantionului
# deviatia standard

t_conf_interval_from_file <- function (filename, alfa) {
    data = scan(filename)
    sample_mean = mean(data)
    s = sd(data)
    n = length(data)
    se = s / sqrt(n)
    critical_t = qt(1 - alfa/2, n-1)
    a = sample_mean - critical_t * s / sqrt(n);
    b = sample_mean + critical_t * s / sqrt(n);
    interval = c(a, b)
    return(interval)

}
