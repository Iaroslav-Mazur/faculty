#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <deque>
#include <queue>

using namespace std;

vector<const char*> vec;
std::deque<const char*> d_vec;


char *longWord(vector<const char*> &v){
    vector<const char*>::iterator it;
    char *max;
    int len = 0;
    for(it = v.begin(); it < v.end(); it++ ){
       int itLen = strlen( (char*)(*it) );

       if(itLen > len){
           max = new char[100];
           strcpy(max, (char*)(*it) );
           len = itLen;
       }
    }
    return max;
}


int more4vocals(vector<const char*> &v){
    int count = 0;

    for(int i = 0; i < v.size(); i++){
        char c = 0, vocals = 0;

        for(c = 0; v[i][c] != '\0'; c++){
            switch (v[i][c]) {
                case 'a':
                    vocals++; 
                    break;
                case 'i':
                    vocals++; 
                    break;
                case 'o':
                    vocals++; 
                    break;
                case 'u':
                    vocals++; 
                    break;
            }            
        } /* end for char in words */
        if(vocals >= 4)
            count++;
    }
    return count;
}


std::deque<const char*> *convertToDeque(vector<const char*> &v){
    std::deque<const char*> *d = new deque<const char*>;

    for(int i = 0; i < v.size(); i++){
        char aux = v[i][0];
        if( aux != 'a' &&
            aux != 'e' &&
            aux != 'o' &&
            aux != 'u')
        {
            char *newChar = new char[100];
            strcpy(newChar, v[i]);
            d->push_back(newChar);
        }
    }

    return d;
}


void sterge(vector<const char*> *v, int lenght){
    vector<const char*>::iterator i;
    i = v->begin();
    while(i != v->end()){
        if( strlen( (char*)(*i) ) > lenght){
            v->erase(i);
        }else{
            i++;
        }
    }
}

char low(char c){
    if(c < 'a'){
        return c + 'a';
    }
    return c;
}

class Compare{
    public:
        char *c;
        Compare(){
            this->c = NULL;
        }
        Compare(const char* my_c){
            this->c = new char[100];
            strcpy(this->c, my_c);
        };

        bool operator () (const char* c1, const char* c2){
            char *t1 = new char[100];
            char *t2 = new char[100];

            strcpy(t1, c1);
            strcpy(t2, c2);

            int min = strlen(t1) < strlen(t2) ? strlen(t1) : strlen(t2);


            for(int i = 0; i < min; i++){
                if(t1[i] > t2[i]){
                    return true;
                }
            }

           return false; 
        };

};

priority_queue<const char*, vector<const char*>, Compare > *getPriority(vector<const char*> *v){
    priority_queue<const char*, vector<const char*>, Compare> *pr;
    pr = new priority_queue<const char*, vector<const char*>,Compare>;

    for(int i = 0; i < v->size(); i++){
        char *c = new char[100];
        strcpy(c, v->at(i));
        pr->push(c);
    }
    return pr;
}

void afisare(vector<const char*> *v){
    for(int i = 0; i < v->size(); i++){
       cout << v->at(i) << endl;
    }
   cout << endl;
}


int main(){
    FILE *f;

    f = fopen("words.in", "r");

    if(!f){
        cout << "Nu am gasit fisierul" << endl;
        return 1;
    }

    char c[100];
    while(fgets(c, 100, f) != NULL){
        char *newChar = new char[100];
        strcpy(newChar, c);

        // filter new-line
        for(int i = 0; newChar[i] != '\0'; i++)
            if(newChar[i] == '\n')
                newChar[i] = '\0';

        vec.push_back(newChar);
    }

    cout <<"Cel mai lung cuvant :" << longWord(vec) << endl;
    cout <<"Cuvinte cu cel putin patru vocale :" << more4vocals(vec) << endl;

    std::deque<const char*> *dq = convertToDeque(vec);
    cout << endl <<  "Elementele din deque : " << endl;
    for(int i = 0; i < dq->size(); i++){
       cout << dq->at(i) << endl;
    }
    cout << endl;

    sterge(&vec, 5);
    afisare(&vec);

    priority_queue<const char*, vector<const char *>, Compare> *q;

    fclose(f);
    return 0;
}
