#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

#define MAX_SIZE 1024


struct Trupa{
    int start, finish;
};


int main(){
    ifstream file("date.txt");
    vector<Trupa> t, solution;
    int n;
    file >> n;

    for(int i = 0; i < n; i++){
        Trupa aux;
        file >> aux.start;
        file >> aux.finish;
        t.push_back(aux);
    }
    file.close();

    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++){
            if(t[i].finish > t[j].finish){
                Trupa aux;
                aux = t[i];
                t[i] = t[j];
                t[j] = aux;
            }
        }

    for(int i = 0; i < t.size(); i++){
        cout << t[i].start << " - " << t[i].finish << endl;
    }
    cout << endl << endl << endl;

    int last_finished = t[0].finish; // prima trupa
    solution.push_back(t[0]); // prima trupa e sigur in solutie

    for(int i = 2; i < n; i++){
        // cout << "Test :" << t[i].start << "-" << t[i].finish << "   cmp :" << last_finished << "   Rezult :" << (t[i].start >= last_finished) << endl;
        if(t[i].start >= last_finished){
            solution.push_back(t[i]);
            last_finished = t[i].finish;
        }
    }

    // afisam solutiile
    for(int i = 0; i < solution.size(); i++){
        cout << solution[i].start << " - " << solution[i].finish << endl;
    }



    return 0;
}
