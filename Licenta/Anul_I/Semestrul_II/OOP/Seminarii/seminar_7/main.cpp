#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
using namespace std;

typedef vector<string> vstring;
bool isValid = true;

ifstream file("data.in");

size_t get_first(string line){
    size_t m = min(line.find('.'), line.find('!'));
    m = min(m, line.find('?'));
    return m;
}

void valid(string line, char c){
    size_t start=0;
    size_t x = line.find(c, start);

    while(x != string::npos){
        if(line[x+1] == c){
            isValid=false;
            continue;
        }
        size_t start=x+1;
        size_t x = line.find(c , start);
    }
}


vstring *split_in_lines(){
    vstring *vec = new vstring();

    string line;
    size_t x = -1 ;
    getline(file, line);
    x = get_first(line);


    while(x != string::npos){
        char buffer[255], aux[255];

        size_t l = line.copy(buffer, x+1, 0);
        buffer[l] = '\0';

        l = line.copy(aux, line.length() ,x+1);
        aux[l] = '\0';
        line = string(aux);

        // liminam spatiile in plus
        while(line[0] == ' '){
            line.erase(0, 1);
        }

        size_t start=0;
        size_t x = line.find(' ', start);

        while(x != string::npos){
            if(line[x+1] == ' '){
                line.erase(x, 1);
                continue;
            }

            size_t start=x+1;
            size_t x = line.find(' ', start);
            cout << "heisadasde " << start << endl;
            cout << "here " << x << endl;
        }
        while(line[line.length()-1] == ' '){
            line.erase(line.length()-1, 1);
        }

        valid(line, '-');
        valid(line, '.');
        valid(line, '!');
        valid(line, '?');


        vec->push_back(string(buffer));

        x = get_first(line);
    }

    if(getline(file, line)){
        isValid = false;
    }

    return vec;
}


void print_vstring(vstring *vec){
    vstring::iterator it;

    for(it=vec->begin(); it < vec->end(); it++ ){
        cout << (string)(*it) << endl;
    }
    cout << endl;

}

int main(){
    vstring *v;
    v = split_in_lines();
    print_vstring(v);

    file.close();
    return 0;
}
