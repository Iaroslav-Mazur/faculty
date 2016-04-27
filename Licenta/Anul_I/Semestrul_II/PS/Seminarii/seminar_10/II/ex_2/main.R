#!/usr/bin/env Rscript

source('../ex_1/main.R')
# alfa
# n
# succes
# p_0
# p_1
# simetrica la dreapta
z = test_proportion(0.2, 150, 20, 0.10,20/150)
z_s = qnorm(1 - 0.10, 0, 1)

if(z > z_s){
    print("Se accepta ipoteza alternativa, se respinge ipoteza nula")
}else{
    print("Nu se poate respinge ipoteza nula")
}
