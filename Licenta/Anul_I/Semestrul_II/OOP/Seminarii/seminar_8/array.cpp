#include "Array.h"
#include <exception>
#include <stdexcept>
#include <stdlib.h>

#ifndef ARRAY_H_
#define ARRAY_H_ 

// ---------------------------------

template<class T>
ArrayIterator<T>::ArrayIterator(){
    this->Current = -1;
}

template<class T>
ArrayIterator<T>&  ArrayIterator<T>::operator ++(){
    this->Current++;

    return (*this);
}

template<class T>
ArrayIterator<T>&  ArrayIterator<T>::operator --(){
    this->Current--;

    return (*this);
}

template<class T>
bool  ArrayIterator<T>::operator =(ArrayIterator<T> &t){
    this->Current = t.Current;
    return true;
}

template<class T>
T* ArrayIterator<T>::GetElement(){
    return (T*)(this->Current);
}



// ---------------------------------
template<class T>
Array<T>::Array(){
    this->Size = 0;
    this->Capacity = 0;
    this->List = NULL;
}

template<class T>
Array<T>::~Array(){
    // for(int i = 0; i < this->Size; i++){
    //     delete (this->List[i]);
    //
    // }

    if(this->List != NULL)
        delete (this->List, this->List + this->Capacity);
}

template<class T>
Array<T>::Array(int capacity){
    this->Size = 0;
    this->Capacity = capacity;
    this->List = new T[this->Capacity];
}

template<class T>
Array<T>::Array(const Array<T> &otherArray){
    // free used memory
    if( otherArray.Size > 0 ){
        for(int i = 0; i < otherArray.Size; i++){
            delete otherArray.List[i];
        }
        delete [] otherArray.List;
    }

    // copy the atributes
    otherArray.List = new T*[this->Capacity];
    otherArray.Capacity = this->Capacity;
    otherArray.Size = this->Size;

    // copy the items
    for(int i = 0; i < this->Size; i++){
        otherArray.List[i] = new T(); // make space 
        *(otherArray.List[i]) = *(this->List[i]); // copy
    }
}

template<class T>
T& Array<T>::operator[] (int index){
    if(index < 0){
        throw std::out_of_range("Index negative found A!");
    }

    if(index >= this->Size){
        throw std::out_of_range("Index out of range !");
    }

    return *(this->List[index]);
}

template<class T>
const Array<T>& Array<T>::operator+= (const T &newElem){
    if(this->Capacity == this->Size){
        T** aux = new T*[this->Capacity*2];

        // if(!aux){
        //     throw std::bad_alloc("Nu am putut aloca memoria !");
        // }

        // copii pointeri la elemente
        for(int i = 0; i < this->Size; i++){
            aux[i] = this->List[i];
        }

        delete [] this->List;
        this->List = aux;
    }

    T* aux_t = new T();
    *aux_t = newElem;
    this->List[this->Size++] = aux_t;

    return (*this);
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const T &newElem){
    if(index < 0){
        throw std::out_of_range("Index negative found A!");
    }

    if(index >= this->Size){
        throw std::out_of_range("Index out of range !");
    }
    
    if(this->Capacity == this->Size){
        T** aux = new T*[this->Capacity*2];

        if(!aux){
            throw std::bad_alloc("Nu am putut aloca memoria !");
        }

        for(int i = 0; i < this->Size; i++){
            aux[i] = this->List[i];
        }

        delete [] this->List;
        this->List = aux;
    }

    // Mutam elementele
    for(int i = this->Size(); i > index; i--){
        this-List[i] = this->List[i-1];
    }

    T& aux = new T(newElem);
    this->List[index] = aux;

    return (*this);
}

template<class T>
const Array<T>& Array<T>::Insert(int index, Array<T> otherArray){
    for(int i = 0; i < otherArray.Size; i++){
        this->Insert(index + i, otherArray[i]);
    }
    return (*this);
}

template<class T>
const Array<T>& Array<T>::Delete(int index){
    // eliberam memoria
    delete this->List[index];

    for(int i = index; i  < this->Size(); i++){
        this->List[i] = this->List[i+1];
    }
    this->Size--;

    return (*this);
}

template<class T>
bool Array<T>::operator=(const Array<T> &otherArray){

    // elimin tot ce am 
    while(this->Size > 0){
        this->Delete(0);
    }

    for(int i = 0; i < otherArray.Size; i++){
        this->Insert(i, otherArray.List[i]);
    }

    return true;
}

template<class T>
void Array<T>::Sort(){
    for(int i = 0; i < this->Size - 1; i++){
        for(int j = i+1; j < this->Size ; j++){
            T* it1 = this->List[i],
               it2 = this->List[j];

            if(it1 > it2){
                T* aux = it1;
                it1 = it2;
                it2 = aux;
            }
        }
    }
}

template<class T>
void Array<T>::Sort( int(*compare)(const T& t1, const T& t2) ){
    for(int i = 0; i < this->Size - 1; i++){
        for(int j = i+1; j < this->Size ; j++){
            T* it1 = this->List[i],
               it2 = this->List[j];

            if( compare(it1, it2) == 2 ){ // apelare compare
                T* aux = it1;
                it1 = it2;
                it2 = aux;
            }
        }
    }
}

template<class T>
void Array<T>::Sort(Compare *compare){
    for(int i = 0; i < this->Size - 1; i++){
        for(int j = i+1; j < this->Size ; j++){
            T* it1 = this->List[i],
               it2 = this->List[j];

            if( *compare(it1, it2) == 1  ){ // apelare compare
                T* aux = it1;
                it1 = it2;
                it2 = aux;
            }
        }
    }
}

template<class T>
int Array<T>::BinarySearch(const T& elem){
    this->Sort();

    int i = 0,
        j = this->Size -1;

    while(i < j){
        int m = (i + j) / 2;

        if( (*this->List[m]) == elem ){
            return m;
        }

        if( (*this->List[m]) > elem ){
            i = m + 1;
        }

        if( (*this->List[m]) < elem ){
            j = m - 1;
        }
    }

    return -1;
}

template<class T>
int Array<T>::BinarySearch(const T& elem, int(*compare)(const T& t1, const T& t2)){
    this->Sort();

    int i = 0,
        j = this->Size -1;

    while(i < j){
        int m = (i + j) / 2;
        T* el = this->List[m];

        if( compare(el, elem) == 0 ){
            return m;
        } 

        if(compare(el, elem) == 1){
            i = m + 1;
        }

        if(compare(el, elem) == -1){
            j = m - 1;
        }
    }

    return -1;
}

template<class T>
int Array<T>::BinarySearch(const T& elem, Compare *compare){
    this->Sort();

    int i = 0,
        j = this->Size -1;

    while(i < j){
        int m = (i + j) / 2;
        T* el = this->List[m];

        if( *compare(el, elem) == 0 ){
            return m;
        } 

        if( *compare(el, elem) == 1){
            i = m + 1;
        }

        if( *compare(el, elem) == -1){
            j = m - 1;
        }
    }
    return -1;
}

template<class T>
int Array<T>::Find(const T& elem){
    for(int i = 0; i < this->Size; i++){
        if( (*this->List[i]) == elem ){
            return i;
        }
    }

    return 0;
}

template<class T>
int Array<T>::Find(const T& elem, int(*compare)(const T& t1, const T& t2)){
    for(int i = 0; i < this->Size; i++){
        T* f = this->List[i];

        if(compare(f, elem)){
            return i;
        }
    }

    return 0;
}

template<class T>
int Array<T>::Find(const T& elem, Compare *comparator){
    for(int i = 0; i < this->Size; i++){
        T* f = this->List[i];

        if(*comparator(f, elem)){
            return i;
        }
    }

    return 0;
}

template<class T>
int Array<T>::GetSize(){
    return this->Size;
}

template<class T>
int Array<T>::GetCapacity(){
    return this->Capacity;
}

template<class T>
ArrayIterator<T> Array<T>::GetBeginIterator(){
    ArrayIterator<T> t;
    t.Current = (int)(this->List);

    return t;
}

template<class T>
ArrayIterator<T> Array<T>::GetEndIterator(){
    ArrayIterator<T> t;
    t.Current = (int)(this->List + this->Size);

    return t;
}



#endif /* ifndef ARRAY_ARRAY_ */    
