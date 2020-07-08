#include <iostream>
#include "MyString.h"
using namespace std;

void TestFunc(const CMyString &strParam){
    cout << strParam[0] << endl;
    cout << strParam[strParam.GetLength()-1] << endl;
}

int main()
{
    CMyString strParam("HelloWorld");
    cout << strParam << endl;
    TestFunc(strParam);

    return 0;
}