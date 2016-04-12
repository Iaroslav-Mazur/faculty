tablou = read.csv("../../data/life_expect.csv", header = TRUE)

rate_male = tablou[['male']]
rate_female= tablou[['female']]


hist(rate_male, breaks = 7, right = F, freq = F)
hist(rate_female, breaks = 7, right = F, freq = F)
