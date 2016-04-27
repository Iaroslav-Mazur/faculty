#!/usr/bin/env Rscript

# n - nr de sample
# range de siguranta
# media esantionului
# deviatia standard

source('../ex_4/main.R')


t_conf_interval_from_file('../data/sample.txt', 1-0.9)
t_conf_interval_from_file('../data/sample.txt', 1-0.95)
t_conf_interval_from_file('../data/sample.txt', 1-0.99)
