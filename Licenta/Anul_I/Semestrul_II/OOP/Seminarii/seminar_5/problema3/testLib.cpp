#include <iostream>
#include "testVir.h"
#include "testLib.h"
 
using namespace std;
void TestLib::init()
{
   cout<<"TestLib::init: Hello World!! "<<endl ;
}
 
//Define functions with C symbols (create/destroy TestLib instance).
extern "C" TestVir* create()
{
    return new TestLib;
}
extern "C" void destroy(TestVir* Tl)
{
   delete Tl ;
}
