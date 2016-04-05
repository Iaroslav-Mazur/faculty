#include <iostream>
#include <dlfcn.h>
// using namespace std;

int main(){
    void* handle = dlopen("./adunare.so", RTLD_LAZY);


    return 0;
}
