#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <string>

using namespace std;


bool find(vector<int> v, int n)
{
    for(vector<int>::iterator it = v.begin(); 
        it != v.end(); it++)
    {
        if(*it == n)
            return true;
    }

    return false;
}

int main(int argc, char *argv[])
{
    int N=0, M=0;
    ifstream file("data.txt");

    cout << "Nr. randuri:";
    cin >> N;

    cout << "Nr. coloane:";
    cin >> M;

    
    int mat[N][M];
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            file >> mat[i][j];


    int nr_lin, nr_col;
    vector<int> linii, coloane;
    cout << "Nr. de linii de afisat:";
    cin >> nr_lin;

    cout << "Nr. de linii de coloane:";
    cin >> nr_col;

    for(int i=0; i<nr_lin; i++)
    {
        cout << "Linia cu nr " << i+1 << " :";
        int aux;
        cin >> aux;
        if(aux > N+1){
            cout << "Ati dat o linie invalida , mai mare decat " << N << endl;
            exit(1);
        }
        if(aux < 1)
        {
            cout << "Ati dat o linie mai mica decat 1" << endl;
            exit(1);

        }
        linii.push_back(aux);
    }

    cout << " ---------- " << endl;
    for(int i=0; i<nr_col; i++)
    {
        cout << "Coloana cu nr " << i+1 << " :";

        int aux;
        cin >> aux;

        if(aux > N+1){
            cout << "Ati dat o coloana invalida , mai mare decat " << M << endl;
            exit(1);
        }
        if(aux < 1)
        {
            cout << "Ati dat o coloana mai mica decat 1" << endl;
            exit(1);
        }
        coloane.push_back(aux);
    }

    vector<string> a_linii;

    for (int i = 0; i <N; i++)
    {
        string aux = "";
        aux = aux + "|";
    
        if (find(linii, N-i))
        {
            //* adaugam toata linia
            for(int j = 0 ; j < M; j++)
                aux += "  " + std::to_string(mat[i][j]) + "  ";
        }else{
            //* verificam per coloana
            for(int j = 0 ; j < M; j++)
            {
                if(find(coloane, j+1)){
                    aux += "  " + to_string(mat[i][j]) + "  ";
                }else
                {
                    aux += "     ";
                }
            }
        }
        aux += "\n";
        a_linii.push_back(aux);
    }

    string aux_2 = "+";
    for(int j = 0; j< M* 5-1 + 10; j++)
        aux_2 += "-";
    aux_2 += "\n";
    a_linii.push_back(aux_2);
    aux_2 =  "";

    for(int j = 0; j< M; j++)
        aux_2 += "  " + std::to_string(j+1) + "  ";
    aux_2 += "\n";
    a_linii.push_back(aux_2);

    cout << endl;
    for(vector<string>::iterator it = a_linii.begin();
        it != a_linii.end(); it++)
        cout << (*it);
    cout << endl;

    // DEBUG(mmicu)
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
            cout << mat[i][j] << " "; 
        cout << endl;

    }
    return 0;
}
