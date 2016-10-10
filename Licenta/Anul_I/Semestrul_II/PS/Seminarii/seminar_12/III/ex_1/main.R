#!/usr/bin/env Rscript

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
