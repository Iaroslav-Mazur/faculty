#include "List.h"
#include <iostream>
#include <cstring>


IntList::IntList(){
    memset(this->Elemente, 0, 1000);
    this->Count = 0;
}

bool IntList::Add(int element){
    if(this->Count == 1000)
        return false;

    this->Elemente[this->Count++] = element;
    std::cout << "Add :" << element << std::endl;
    return true;
}

bool IntList::Insert(int index, int element){
    if(index < 0 || index > this->Count
       || this->Count == 1000)
        return false;

    for(int i = this->Count; i >= index; i--)
        this->Elemente[i] = this->Elemente[i-1];

    this->Elemente[index] = element;
    this->Count++;

    return true;
}

bool IntList::Delete(int index){
    if(index < 0 || index >= this->Count)
        return false;

    for(int i = index; i < this->Count - 1; i++)
        this->Elemente[i] = this->Elemente[i+1];

    this->Count--;
    return true;
}

void IntList::Clear(){
    this->Count = 0;
}

int IntList::GetCount(){
    return this->Count;
}

int IntList::Get(int index){
    if(index < 0 || index > 999)
        return -1;

    return this->Elemente[index];
}

int IntList::IndexOf(int valoare, int startPosition){
    for(int i = startPosition; i < this->Count; i++)
        if(this->Elemente[i] == valoare)
            return i;

    return -1;
}

void IntList::RemoveDuplicates(){
    // numere pana la 1000
    int v[1001];
    for(int i = 0; i < 1001; i++)
        v[i] = 0;

    for(int i = 0; i < this->Count; i++)
        v[this->Elemente[i]]++;

    for(int i = 0; i < 1001; i++) 
        while(v[i] > 1){
            this->Delete(this->IndexOf(i, 0));
            v[i]--;
        }
}

void IntList::Intersection(IntList *withList, IntList *resultList){
    resultList->Clear();

    for(int i = 0; i < withList->GetCount(); i++)
        if(this->IndexOf(withList->Get(i), 0) != -1)
            resultList->Add(withList->Get(i));

    resultList->RemoveDuplicates();
}

void IntList::Reunion(IntList *withList, IntList *resultList){
    resultList->Clear();

    for(int i = 0; i < withList->GetCount() && resultList->GetCount() < 1000; i++)
        resultList->Add(resultList->Get(i));

    for(int i = 0; i < this->Count && resultList->GetCount() < 1000; i++)
        resultList->Add(this->Elemente[i]);

    resultList->RemoveDuplicates();
}

void IntList::Sort(){
    for(int i = 0; i < this->Count -1; i++)
        for(int j = i+1; j < this->Count; j++)
            if(this-Elemente[i] < this-Elemente[j]){
                int aux = this->Elemente[i];
                this->Elemente[i] = this->Elemente[j];
                this->Elemente[j] = aux;
            }
}

void IntList::Reverse(){
    for(int i = 0; i < this->Count / 2; i++){
        int aux = this->Elemente[i];
        this->Elemente[i] = this->Elemente[this->Count - i];
        this->Elemente[this->Count - i] = aux;
    }
}




void IntList::deb(){
    std::cout<< "Count :" << this->Count << std::endl;

    for(int j = 0; j < this->Count; j++){
        std::cout << this->Elemente[j] << " ";
    }
    std::cout << std::endl;
}
