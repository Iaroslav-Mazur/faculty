data = read.csv("../../data/life_expect.csv", header = T)
male = data[["male"]]
female = data[["female"]]

print("Male")
mean(male)
median(male)

print("Female")
mean(female)
median(female)
