#!/usr/bin/env Rscript

#tip = [asim_d, asim_s, sim]
test_t_fisier <- function (tip, filename, alfa, mean) {

   data = scan(filename);
   sample_mean = mean(data);
   n = length(data);
   s = sd(data);
   se = s / sqrt(n);

   scor = (sample_mean - mean) / se
   if(tip == "asim_d"){
        c_t = qt(1 - alfa, n-1);
        if(scor > c_t){
            print("Se respinde ipoteza nula, se accepta ipoteza alternativa")
        }else{
            print("Nu se poate respinge ipoteza nula, se accepta")
        }
   }

   if(tip == "asim_s"){
        c_t = qt(alfa, n-1);
        if(scor < c_t){
            print("Se respinde ipoteza nula, se accepta ipoteza alternativa")
        }else{
            print("Nu se poate respinge ipoteza nula, se accepta")
        }

   }

   if(tip == "sim"){
        c_t = qt(1 - alfa/2, n-1);
        if(abs(scor) >  abs(c_t)){
            print("Se respinde ipoteza nula, se accepta ipoteza alternativa")
        }else{
            print("Nu se poate respinge ipoteza nula, se accepta")
        }

   }
    
}

test_t <- function (tip, sample_mean, se, alfa, mean ) {
   scor = (sample_mean - mean) / se
   if(tip == "asim_d"){
        c_t = qt(1 - alfa, n-1)
        if(scor > c_t){
            print("Se respinde ipoteza nula, se accepta ipoteza alternativa")
        }else{
            print("Nu se poate respinge ipoteza nula, se accepta")
        }
   }

   if(tip == "asim_s"){
        c_t = qt(alfa, n-1)
        if(scor < c_t){
            print("Se respinde ipoteza nula, se accepta ipoteza alternativa")
        }else{
            print("Nu se poate respinge ipoteza nula, se accepta")
        }

   }

   if(tip == "sim"){
        c_t = qt(1 - alfa/2, n-1)
        if(abs(scor) >  abs(c_t)){
            print("Se respinde ipoteza nula, se accepta ipoteza alternativa")
        }else{
            print("Nu se poate respinge ipoteza nula, se accepta")
        }
   }
    
}
