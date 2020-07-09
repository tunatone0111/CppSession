#include <iostream>
#include "MyStringEx.h"
using namespace std;

int main()
{
    CMyStringEx strTest;
    strTest.SetString("I am a boy.");
    cout << strTest.GetString() << endl;

    int nIndex = strTest.Find("am");
    cout << "Index: " << nIndex << endl;

    return 0;
}