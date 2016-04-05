#include <iostream>
#include "List.cpp"

using namespace std;

void populeaza(IntList *l){
    l->Clear();
    l->Add(1);
    l->Add(1);
    l->Add(2);
    l->Add(3);
    l->Add(4);
}

void populeaza2(IntList *l){
    l->Clear();
    l->Add(1);
    l->Add(1);
    l->Add(2);
    l->Add(3);
    l->Add(4);
    l->Add(5);
    l->Add(6);
}

void test_reuniune(){
    IntList *a, *b, *c;

    a = new IntList();
    populeaza(a);

    b = new IntList();
    populeaza2(b);

    c = new IntList();

    a->deb();
    b->deb();
    a->Reunion(b, c);
    c->deb();
}


int main(){
    // IntList *a;
    // a = new IntList();
    // a->Add(1);
    // a->Insert(1, 2);
    // a->Add(3);
    // a->deb();
    //
    test_reuniune();
    return 0;
}
