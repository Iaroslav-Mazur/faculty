#ifndef _Matrice
#define _Matrice
class Matrice{
    private:
        int Matrix[3][3];

    public:
        Matrice();
        Matrice(int **array);
        Matrice(const Matrice&altaMatrice );

        void Print();

        Matrice operator - (const Matrice &operand);
        
        Matrice operator + (const Matrice &operand);

        Matrice& operator = (Matrice &);


        friend int operator ~(const Matrice &matrice);

        friend Matrice operator !(const Matrice &matrice);

        friend bool operator ==(const Matrice &, const Matrice &);


};

#endif
