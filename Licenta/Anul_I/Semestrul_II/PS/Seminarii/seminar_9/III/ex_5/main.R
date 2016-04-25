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

intervale <- function ( dispersie, medie, l_est, incredere) {
    a = zconficande_interval(dispersie, medie, l_est, incredere)
    print("Diferenta ")
    print(incredere)
    print(a[2] - a[1])

}


intervale(25, 60, 35, 0.9)
print('------------')
intervale(25, 60, 35, 0.95)
print('------------')
intervale(25, 60, 35, 0.99)
print('------------')
intervale(25, 60, 35, 1)
