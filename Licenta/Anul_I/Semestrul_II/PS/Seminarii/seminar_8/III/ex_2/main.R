sample = c(1, 91, 38, 72, 13, 27, 11, 19, 5, 22, 20, 19, 8, 17, 11, 15, 13, 23, 14, 17)

second <- function(sample){
    q1 = as.vector(quantile(sample))[1+1]
    q3 = as.vector(quantile(sample))[3+1]
    iqr = q3 - q1

    new_sample = vector()

    for(i in 1:length(sample)){
        if(sample[i] > q1 - 1.5 * iqr && sample[i] < q3 + 1.5 * iqr){
            new_sample = c(new_sample, sample[i]);
        }
    }

    return(new_sample)
}

second_ab <- function(sample){
    q1 = as.vector(quantile(sample))[1+1]
    q3 = as.vector(quantile(sample))[3+1]
    iqr = q3 - q1

    new_sample = vector()

    for(i in 1:length(sample)){
        if(sample[i] < q1 - 1.5 * iqr || sample[i] > q3 + 1.5 * iqr){
            new_sample = c(new_sample, sample[i]);
        }
    }

    return(new_sample)
}

second(sample)
second_ab(sample)


