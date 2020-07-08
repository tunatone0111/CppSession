#include <iostream>
#include "MyString.h"
using namespace std;

CMyString TestFunc(void){
    CMyString strTest("TestFunc() return");
    cout << strTest << endl;

    return strTest;
}

int main()
{
    CMyString strLeft("Hello"), strRight("World"), strResult;

    strResult = strLeft + strRight;
    cout << strResult << endl;

    cout << strLeft << endl;
    strLeft += CMyString("World");
    cout << strLeft << endl;

    return 0;
}