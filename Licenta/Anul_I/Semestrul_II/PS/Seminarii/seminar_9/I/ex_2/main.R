#!/usr/bin/env Rscript

interval <- function (u, r, cate) {
    d = sqrt(r)
    print(u - (cate/2)*d)
    print(u + (cate/2)*d)
}
