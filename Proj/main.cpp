#include <iostream>
#include "MyString.h"
using namespace std;

void TestFunc(const CMyString &strParam){
    cout << strParam[0] << endl;
    cout << strParam[strParam.GetLength()-1] << endl;
}

int main()
{
    CMyString strLeft("Test"), strRight("String");

    if(strLeft == strRight)
        cout << "same" << endl;
    else
        cout << "different" << endl;

    strLeft = CMyString("String");

    if(strLeft != strRight)
        cout << "different" << endl;
    else
        cout << "same" << endl;

    return 0;
}