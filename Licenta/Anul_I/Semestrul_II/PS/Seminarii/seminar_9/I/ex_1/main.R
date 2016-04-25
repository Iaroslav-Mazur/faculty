#!/usr/bin/env Rscript

normal_density <- function (u, r, limit) {
    d = sqrt(r)
    t = seq(-limit, limit, length=400)
    f = (1 / ( d * sqrt(2 * pi)) ) * exp(- (t-u) ^ 2 / (2 * r));
    plot(t, f, type="l", lwd=1);
}
