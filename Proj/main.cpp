#include <iostream>
#include "MyString.h"
using namespace std;

void TestFunc(const CMyString &param){
    cout << param.GetString() << endl;
    return;
}

int main()
{
    CMyString strData;
    strData.SetString("Hello");
    TestFunc(strData);

    return 0;
}