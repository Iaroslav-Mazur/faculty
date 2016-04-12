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

first_ab<-function(sample){
    m = mean(sample)
    s = sd(sample)

    new_sample = vector()
    j = 0
    for(i in 1:length(sample)){
        if( sample[i] < m - 2 * s || sample[i] > m + 2 * s){
            j = j + 1
            new_sample = c(new_sample, sample[i]);
        }
    }

    return(new_sample)
}

sample = scan("../../data/sample2.txt")
first(sample)
second(sample)
print("Aberante ")
first_ab(sample)
second_ab(sample)


