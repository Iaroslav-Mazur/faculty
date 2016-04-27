#!/usr/bin/env Rscript

source('../ex_1/main.R')
# n - nr de sample
# range de siguranta
# media esantionului
# deviatia standard
print('A)    ')
t_conf_interval(49, 1-0.99, 12, 1.75)
t_conf_interval(49, 1-0.95, 12, 1.75)
print('B)    ')
t_conf_interval(49, 1-0.95, 13.5, 1.25)
