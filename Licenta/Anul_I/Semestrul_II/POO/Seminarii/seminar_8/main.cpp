#include <iostream>
#include "array.cpp"
using namespace std;
struct st{
    int t;
};

Array<int> a;


int main(int argc, char *argv[])
{

    for(int i = 1; i < 9 ; i++){
        a += i;
    }

    // for(int i = 0; i < a.GetSize(); i++){
    //     cout << a[i] << " ";
    // }
    //
    // cout << endl;

    return 0;
}

