#include <exception>
#include <stdexcept>
class Compare
{
public:
 virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator
{
private:
 int Current; // mai adaugati si alte date si functii necesare pentru iterator
public:
 ArrayIterator();
 ArrayIterator& operator ++ ();
 ArrayIterator& operator -- ();
 bool operator= (ArrayIterator<T> &);
 bool operator!=(ArrayIterator<T> &);
 T* GetElement();
};
template<class T>
class Array
{
private:
 T** List; // lista cu pointeri la obiecte de tipul T*
 int Capacity; // dimensiunea listei de pointeri
 int Size; // cate elemente sunt in lista
public:
 Array() // Lista nu e alocata, Capacity si Size = 0
 {
    this->Size = 0;
    this->Capacity = 0;
    this->List = NULL;
 }

 ~Array() // destructor
 {
    for(int i = 0; i < this->Size; i++){
        delete this->List[i];
    }

    delete [] this->List;
 }

 Array(int capacity) // Lista e alocata cu 'capacity' elemente
 {
    this->Size = 0;
    this->Capacity = capacity;
    this->List = new T[this->Capacity];
 }

 Array(const Array<T> &otherArray) // constructor de copiere
 {
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

 T& operator[] (int index) // arunca exceptie daca index este out of range
 {
    if(index < 0){
        throw std::out_of_range("Index negative found A!");
    }

    if(index >= this->Size){
        throw std::out_of_range("Index out of range !");
    }

    T& aux = new T();
    aux = (T)(*this->List[index]);
    return aux;
 }

 const Array<T>& operator+=(const T &newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
 {
    
    if(this->Capacity == this->Size){
        T** aux = new T*[this->Capacity*2];

        if(!aux){
            throw std::bad_alloc("Nu am putut aloca memoria !");
        }

        // copii pointeri la elemente
        for(int i = 0; i < this->Size; i++){
            aux[i] = this->List[i];
        }

        delete [] this->List;
        this->List = aux;
    }

    T aux_t = new T();
    aux_t = newElem;
    this->List[this->Size++] = aux_t;

    return (*this);
 }

// //  const Array<T>& Insert(int index, const T &newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie

 const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
 {
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

    }


    return (*this);

 }

 const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

 bool operator=(const Array<T> &otherArray);

 void Sort(); // sorteaza folosind comparatia intre elementele din T

 void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie

 void Sort(Compare *comparator); // sorteaza folosind un obiect de comparatie

//  functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

 int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
 int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
 int BinarySearch(const T& elem, Compare *comparator);//  cauta un element folosind binary search si un comparator
 int Find(const T& elem); // cauta un element in Array
 int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie
 int Find(const T& elem, Compare *comparator);//  cauta un element folosind un comparator
 int GetSize(); 
 int GetCapacity();
 ArrayIterator<T> GetBeginIterator();
 ArrayIterator<T> GetEndIterator();
};
