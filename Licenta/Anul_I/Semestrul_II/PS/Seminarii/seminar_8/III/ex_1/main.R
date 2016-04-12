sample = c(1, 91, 38, 72, 13, 27, 11, 19, 5, 22, 20, 19, 8, 17, 11, 15, 13, 23, 14, 17)

first <-function(sample){
    m = mean(sample)
    s = sd(sample)

    new_sample = vector()

    for(i in 1:length(sample)){
        if(sample[i] >= m - 2 * s & sample[i] <= m + 2 * s){
            new_sample = c(new_sample, sample[i]);
        }
    }

    return(new_sample)
}

first_ab <-function(sample){
    m = mean(sample)
    s = sd(sample)

    new_sample = vector()

    for(i in 1:length(sample)){
        if(sample[i] < m - 2 * s | sample[i] > m + 2 * s){
            new_sample = c(new_sample, sample[i]);
        }
    }

    return(new_sample)
}

first(sample)
first_ab(sample)
