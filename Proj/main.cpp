#include <iostream>
#include "MyStringEx.h"
using namespace std;

int main()
{
    CMyStringEx strTest;

    strTest.SetString("멍멍이아들");
    cout << (char*)strTest << endl;

    strTest.SetString("Hello");
    cout << (char*)strTest << endl;

    return 0;

}