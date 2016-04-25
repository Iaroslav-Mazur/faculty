#!/usr/bin/env Rscript

selection_mean <- function (filename) {
    x = scan(filename)
    m = mean(x)
    return(m)
}

selection_mean("../../date/sample.txt")
