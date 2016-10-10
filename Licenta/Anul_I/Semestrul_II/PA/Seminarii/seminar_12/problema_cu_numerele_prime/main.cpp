#include <iostream>
#include <math.h>

using namespace std;

bool can_be_made(long prim, long cifre[], long n){
    bool used_c[n];
    long r = prim;
    for(int i = 0; i < n; i++){
        used_c[i] = false;
    }

    char aux;
    while(prim){
        aux = prim % 10;
        prim = prim / 10;

        bool ok = false;
        for(int i = 0; i < n; i++){
            if(cifre[i] == aux && used_c[i] == false ){
                used_c[i] = true;
                ok = true;
                break;
            }
        }

        if(ok == false){
            return ok;
        }

    }

    return true;
}

int main(){
    long n, cifre[10];
    cin >> n;

    for(long i = 0; i < n; i++){
        cin >> cifre[i];
    }

    long max_prim = pow(10, n);
    bool prim[max_prim];

    for(long i = 0; i < max_prim; i++ ){
        prim[i] = true;
    }

    prim[0] = false;
    prim[1] = false;

    for(long i = 2; i < max_prim; i++){
        if(prim[i]){
            for(long j = i + i; j < max_prim; j = j + i){
                prim[j] = false;
            }
        }
    }

    // for(int i = 1; i < max_prim; i++){
    //     if(prim[i]){
    //         cout << i << endl;
    //     }
    // }


    cout << " ----- " << endl;
    int c = 0;
    for(int i = 1; i < max_prim; i++){
        if(prim[i] && can_be_made(i, cifre, n)){
            cout << i << endl;
            c++;
        }
    }
    cout << "Total :" << c << endl;
    return 0;
}
