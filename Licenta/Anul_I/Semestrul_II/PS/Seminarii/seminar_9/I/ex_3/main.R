#!/usr/bin/env Rscript


normal_density <- function (u, r, limit) {
    d = sqrt(r)
    t = seq(-limit, limit, length=400)
    f = (1 / ( d * sqrt(2 * pi)) ) * exp(- (t-u) ^ 2 / (2 * r));
    plot(t, f, type="l", lwd=1);
}

interval <- function (u, r, cate) {
    d = sqrt(r)
    print(u - (cate/2)*d)
    print(u + (cate/2)*d)
}

print(" 0 - 4")
a = 0
b = 4
normal_density(a, b, 6)
interval(a, b, 2)
interval(a, b, 4)
interval(a, b, 6)
print("------------------")

print(" 2 - 5")
a = 2
b = 5
normal_density(a, b, 6)
interval(a, b, 2)
interval(a, b, 4)
interval(a, b, 6)
print("------------------")

print(" 1 - 9")
a = 1
b = 9
normal_density(a, b, 6)
interval(a, b, 2)
interval(a, b, 4)
interval(a, b, 6)
print("------------------")
