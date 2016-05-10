#!/usr/bin/env Rscript
# tip = [asim_d, asim_s, sim]
# tip, n, mean, x, alfa, deviatie(sigma)
z_test <- function (tip, n, mean, sample_mean, alfa, dis) {
    critical_z = 0;
    scor = (sample_mean - mean) / (dis/sqrt(n));

    if(tip == "asim_d"){
        critical_z = qnorm(1 - alfa, 0, 1);
        if(scor > critical_z){
            print("Se respinge ipoteza nula, se accepta impoteza alternativa");
        }else{
            print("Nu se poate respinge ipoteza nula, se accepta ipoteza nula");
        }
    }

    if(tip == "asim_s"){
        critical_z = qnorm(alfa, 0, 1);

        if(scor < critical_z){
            print("Se respinge ipoteza nula, se accepta impoteza alternativa");
        }else{
            print("Nu se poate respinge ipoteza nula, se accepta ipoteza nula");
        }
    }

    if(tip == "sim"){
        critical_z = qnorm(1 - alfa/2, 0, 1);
        if(abs(scor) > abs(critical_z)){
            print("Se respinge ipoteza nula, se accepta impoteza alternativa");
        }else{
            print("Nu se poate respinge ipoteza nula, se accepta ipoteza nula");
        }
    }

    rez = c(scor, critical_z)
    print(rez)
}

dis = 85
n = 100
sample_mean = 97
media_popupatiei = 100
print("ipoteza nula este ca nu pot pretinde")
print("ipoteza alternativa este ca pot pretinde")

alfa = 0.05
z_test("asim_s", n, media_popupatiei, sample_mean, alfa, dis);

alfa = 0.01
z_test("asim_s", n, media_popupatiei, sample_mean, alfa, dis);
