#!/usr/bin/env Rscript

source('../ex_1/main.R')
# alfa
# n
# succes
# p_0
# p_1

# simetrica la dreapta
z = test_proportion(0.01, 48, 17, 0.25, 17/48)
z_s = qnorm(0.25, 0, 1)

if(z < z_s){
    print("Se accepta ipoteza alternativa, se respinge ipoteza nula")
}else{
    print("Nu se poate respinge ipoteza nula")
}
