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
    
   scor = (sample_mean - mean) / se;
   if(tip == "asim_d"){
        scor = (sample_mean - mean) / se;
        c_t = qt(1 - alfa, n-1)
        if(scor > c_t){
            print("Se respinde ipoteza nula, se accepta ipoteza alternativa")
        }else{
            print("Nu se poate respinge ipoteza nula, se accepta")
        }
   }

   if(tip == "asim_s"){
        scor = (sample_mean - mean) / se;
        c_t = qt(alfa, n-1)
        if(scor < c_t){
            print("Se respinde ipoteza nula, se accepta ipoteza alternativa")
        }else{
            print("Nu se poate respinge ipoteza nula, se accepta")
        }

   }

   if(tip == "sim"){
        scor = (sample_mean - mean) / se;
        c_t = qt(1 - alfa/2, n-1)
        if( abs(scor) >  abs(c_t) ){
            print("Se respinde ipoteza nula, se accepta ipoteza alternativa")
        }else{
            print("Nu se poate respinge ipoteza nula, se accepta")
        }
   }
    
}

filename = "../data/history.txt"
data = c(36, 32, 28, 33, 41, 28, 31, 26, 29, 34);
n = 100
s = 0.25
se = s / sqrt(n)
sample_mean = 11.9
mean = 80

alfa = 0.01
test_t_fisier("sim", filename, alfa, mean )

alfa = 0.05
test_t_fisier("sim", filename, alfa, mean )
