#!/usr/bin/env Rscript

selection_mean <- function (filename, d_2) {
    x = scan(filename)

    d = d_2 / length(x)
    m = mean(x)
    print("Media :");
    print(m)

    print("Dispersia :");
    print(d)
}

selection_mean("../../date/sample.txt", 2)
