#include <iostream>
#include "MyString.h"
using namespace std;

void TestFunc(const CMyString &strParam){
    cout << (char*)strParam << endl;
    return;
}

int main()
{
    CMyString strData("Hello");

    ::TestFunc(strData);
    ::TestFunc(CMyString("World"));

    return 0;
}