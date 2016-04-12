get_freq <- function(search, esantion){
    nr_ap = 0
    for(i in 1:length(esantion)){
        if(esantion[i] == search){
            nr_ap = nr_ap + 1;
        }
    }

    return(nr_ap)
}


get_modul <- function(esantion){
    max = esantion[1]

    for(item in 1:length(esantion)){
        ap_item = get_freq(esantion[item], esantion)
        ap_max = get_freq(max, esantion)
        if(ap_item > ap_max){
            max = esantion[item];
        }
    }

    return(item)
}

sample = scan("../../data/sample1.txt")
get_modul(sample)

