#!/usr/bin/env Rscript

zconficande_interval <- function (filename, incredere) {
        x = scan(filename)
        l_est = length(x);
        medie = mean(x)
        dispersite = 2;

        alfa = 1 - incredere
        sigma = sqrt(dispersite)
        critical_z = qnorm(1 - alfa/2, 0, 1)

        a = medie - critical_z * sigma / sqrt(l_est)
        b = medie + critical_z * sigma / sqrt(l_est)
        interval = c(a, b) 
        return(interval)
}

zconficande_interval("../../date/sample.txt", 0.95)
