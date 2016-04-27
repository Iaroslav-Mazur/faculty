#!/usr/bin/env Rscript

source('../ex_1/main.R')
# alfa
# n
# succes
# p_0
# p_1

# simetrica la simetrica
z = test_proportion(0.01, 110, 15, 0.10,15/110)
z_s = qnorm(1- 0.10/2, 0, 1)

if(abs(z) > abs(z_s)){
    print("Se accepta ipoteza alternativa, se respinge ipoteza nula")
}else{
    print("Nu se poate respinge ipoteza nula")
}
