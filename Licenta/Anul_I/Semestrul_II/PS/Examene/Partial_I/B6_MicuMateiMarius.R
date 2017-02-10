#!/usr/bin/env Rscript

# Ex 1
print("Exercitiu 1");
este_mai_mic <- function (sample_data, medie) {
    medie_sample_data = mean(sample_data);
    if(medie_sample_data < medie){
        print("Nivelu mediu de fosfor este mai mic decat media data!")
        print("Media primita:");
        print(medie );

        print("Media calculata:");
        print(medie_sample_data);
    }else{
        print("Nivelu mediu de fosfor este mai mare sau egal decat media data!")
        print("Media primita:");
        print(medie );

        print("Media calculata:");
        print(medie_sample_data);
    }
    
}


data_ex_1 = c(5.2, 5.1, 4.9, 4.8, 5.8, 6.4);
medie_ex_1 = 5.6;
este_mai_mic(data_ex_1, medie_ex_1);

print("");
print("");

# Ex 2
print("Exercitiu 2");
T_test_means <- function (tip, alfa, n1, n2, s1, s2, sample_mean1, sample_mean2) {
    m0 = 0; 

    # testul f
    critical_F_s = qf(alfa/2, n1-1, n2-1);
    critical_F_d = qf(1 - alfa/2, n1-1, n2-1);

    F_score = (s1 * s1) / (s2 * s2);

    if(F_score < critical_F_s | F_score > critical_F_d){
        df = min(n1 - 1, n2 - 1);
        combined_s = sqrt( (s1 ^ 2) / n1 + (s2 ^ 2) / n2 );
    }else{
        df = n1 + n2 - 2;
        combined_s = sqrt(((n1 - 1)*s1^2 + (n2 - 1)*s2^2)/df)*sqrt(1/n1+1/n2);
    }

	t_score = ( sample_mean1 - sample_mean2 -m0) / combined_s;

	if(tip == "sim_st"){
		critical_t = qt(2 * alfa, df);

        print("Simetric Stanga")
        if(critical_t < t_score){
            print("Se respinde ipoteza nula");
        }else{
            print("Nu se poate respinge ipoteza nula");
        }
	}

	if(tip == "sim_dr"){
		critical_t = qt(1 - alfa, df);

        print("Simetric Dreapta")
        if(critical_t > t_score){
            print("Se respinde ipoteza nula");
        }else{
            print("Nu se poate respinge ipoteza nula");
        }
	}

	if(tip == "sim"){
		critical_t = qt(alfa/2 , df);

        print("Simetric ")
        if( abs(critical_t) < abs(t_score)){
            print("Se respinde ipoteza nula");
        }else{
            print("Nu se poate respinge ipoteza nula");
        }
	}

}

n1 = 82;
n2 = 77;
sample_mean1 = 110;
sample_mean2= 115;
s1 = 12.3;
s2 = 13.4;

print("Ipoteza nula : mediile nu difera");
print("Ipoteza alternativa : mediile difera");
T_test_means("sim", 0.01, n1, n2, s1, s2, sample_mean1, sample_mean2);

print("");
print("");

# Ex 3
print("Exercitiu 3");
# tip = [asim_d, asim_s, sim]
# tip, n, mean, x, alfa, dispersia(sigma)
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


# tip, n, mean, x, alfa, deviatie(sigma)
print("Ipoteza nula: mediile nu difera")
print("Ipoteza alternativa: mediile difera")

data = c(0.8434, 0.8346, 0.8361);
tip = "sim";
n = length(data);
sample_mean = mean(data);
mean = 0.835;
dev = 0.004;
dis = dev * dev;
alfa = 0.01;

z_test(tip, n, mean, sample_mean, alfa, dis);


print("");
print("");

# Ex 4
print("Exercitiu 4");
zconficande_interval <- function (dispersite, medie, l_est, incredere) {
        alfa = 1 - incredere
        sigma = sqrt(dispersite)
        critical_z = qnorm(1 - alfa/2, 0, 1)
        a = medie - critical_z * sigma / sqrt(l_est)
        b = medie + critical_z * sigma / sqrt(l_est)
        interval = c(a, b) 
        return(interval)
}

alfa = 0.9;
dispersie = 20;
n = 130;
medie = 23;
print("Intervalil este :");
zconficande_interval(dispersie, medie, n, alfa);


print("");
print("");

# Ex 5
print("Exercitiu 5");
data = c(7.4, 9, 8.25, 9, 9.95, 9.75, 8.5, 9.5, 8.5, 7, 6.33, 8.5, 9.33, 
         8.75, 5.25, 7.50, 8.25, 9.33, 8.75, 5.55, 9.60, 6.50, 7.20, 6.33, 9.5, 9.7,
         8.66, 9.25, 8.75, 9.25, 9.55, 9.75, 5.5, 9.5, 6.5, 9, 9.33, 9.75, 9.5);

print("Media este :");
print(mean(data));
print("");

print("Mediana este:");
print(median(data));
print("");


print("Deviatia standard este:");
sd(data);
print("");

print("Quartilele sunt :");
quantile(data);
print("");

find_ab <-function(sample){
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
print("");
aberante = find_ab(data);
if(length(aberante) > 0){
    print("Avem valori aberante si astea sunt :");
    print(aberante);
}else{
    print("Nu avem valori aberante si astea sunt :");
}
