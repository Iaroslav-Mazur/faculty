#!/usr/bin/env Rscript

zconficande_interval <- function (dispersite, medie, l_est, incredere) {
        alfa = 1 - incredere
        sigma = sqrt(dispersite)
        critical_z = qnorm(1 - alfa/2, 0, 1)
        a = medie - critical_z * sigma / sqrt(l_est)
        b = medie + critical_z * sigma / sqrt(l_est)
        interval = c(a, b) 
        return(interval)
}

zconficande_interval(140*140, 1280, 100, 0.99)
