#!/usr/bin/env Rscript

# tip =[asim_st, asim_dr, sim]
z_test_means <- function (tip, alfa, n1, n2, dis_1, dis_2, sample_mean1, sample_mean2) {
    combined = sqrt(dis_1 ^ 2 / n1 + dis_2 ^ 2/n2);
    m0 = 0;
    z = 0;
    z_score = (sample_mean1 - sample_mean2 - m0 ) / combined;
    if(tip == "asim_st"){
        z = qnorm(alfa, 0, 1);

        print("Asimetric Stanga ")
        if(z_score < z){
            print("Se respinge ipoteza NULA");
        }else{
            print("Nu se respinge ipoteza NULA");
        }
    }

    if(tip == "asim_dr"){
        z = qnorm(1 - alfa, 0, 1);

        print("Asimetric Deeapta ")
        if(z_score > z){
            print("Se respinge ipoteza NULA");
        }else{
            print("Nu se respinge ipoteza NULA");
        }
    }

    if(tip == "sim"){
        z = qnorm(1 - alfa/2, 0, 1);

        print("Simetrica ")
        if(abs(z_score) > abs(z)){
            print("Se respinge ipoteza NULA");
        }else{
            print("Nu se respinge ipoteza NULA");
        }
    }
}
n1 = 80
sample_mean1 = 160
dis1 = 3.24 * 3.24

n2 = 70
sample_mean2 = 155
dis2 = 2.25 * 2.25

# tip, alfa, n1, n2, dis1, dis2, samp1, samp2
z_test_means("sim", 0.01, n1, n2, dis1, dis2, sample_mean1, sample_mean2 )

