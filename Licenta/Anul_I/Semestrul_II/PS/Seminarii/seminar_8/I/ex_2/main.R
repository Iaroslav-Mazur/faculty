tablou = read.csv("../../data/unemploy2012.csv", header = T, sep = ';')
rate = tablou[['rate']]
rate

interval = seq(4,14, 2)
interval = c(0, interval, 30)
interval

hist(rate, breaks = interval, right = F, freq = F)

