#!/usr/bin/env Rscript

x1 = c(12.512, 12.869, 19.098, 15.350, 13.297, 15.589);
x2 = c(11.074, 9.686, 12.164, 8.351, 12.182, 11.489);

n1 = length(x1);
n2 = length(x2);

s1 = sd(x1);
s2 = sd(x2);

F_test <- function (tip, alfa, n1, n2, s1, s2) {
    f = (s1 * s1) / ( s2 * s2 );

    if(tip == "asim_st" ){
        f_critic = qf(alfa, n1 - 1, n2 - 1);

        print("Asimetric Stanga");
        if(f > f_critic){
            print("Se respinge ipoteza NULA");
        }else{
            print("Nu se respinge ipoteza NULA");
        }
    }

    if(tip == "sim" ){
        f_critic_s = qf(alfa/2 , n1 - 1, n2 - 1);
        f_critic_d = qf(1 - alfa/2, n1 - 1, n2 - 1);

        print("Asimetric Stanga");
        if(f < f_critic_s  || f > f_critic_d){
            print("Se respinge ipoteza NULA");
        }else{
            print("Nu se respinge ipoteza NULA");
        }
    }
    
}

alfa = 0.01
F_test("sim", alfa, n1, n2, s1, s2 );

alfa = 0.05
F_test("sim", alfa, n1, n2, s1, s2 );
