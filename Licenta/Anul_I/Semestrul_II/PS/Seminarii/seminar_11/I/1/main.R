#!/usr/bin/env Rscript
# tip = [asim_d, asim_s, sim]
# tip, n, mean, x, alfa, deviatie(sigma)
z_test <- function (tip, n, mean, sample_mean, alfa, dis) {
    critical_z = 0;
    if(tip == "asim_d"){
        critical_z = qnorm(1 - alfa, 0, 1);
    }

    if(tip == "asim_s"){
        critical_z = qnorm(alfa, 0, 1);
    }

    if(tip == "sim"){
        critical_z = qnorm(1 - alfa/2, 0, 1);
    }

    scor = (sample_mean - mean) / (dis/sqrt(n));
    return(scor);
}
