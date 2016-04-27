#!/usr/bin/env Rscript

test_proportion <- function (alfa, n, succese, p_0, p_1) {
    z = (p_1 - p_0) / sqrt(p_0 * ( 1 - p_0 ) / n);
    return(z)
}
