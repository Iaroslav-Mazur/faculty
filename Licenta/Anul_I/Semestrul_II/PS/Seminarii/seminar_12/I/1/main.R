#!/usr/bin/env Rscript

# tip =[asim_st, asim_dr, sim]
z_test_means <- function (tip, alfa, n1, n2, dev_1, dev_2) {
    combined = sqrt(dev_1 ^ 2 / n1 + dev_2 ^ 2/n2);
    z = 0;
    if(tip = "asim_st"){
        z = qnorm(alfa, 0, 1);
    }

    if(tip = "asim_dr"){
        z = qnorm(1 - alfa, 0, 1);
    }

    if(tip = "sim"){
        z = qnorm(1 - alfa/2, 0, 1);
    }

    z_score = (n1 - n2 -)
}
