#include <iostream>
#include "MyStringEx.h"
using namespace std;

CMyString operator+(const char *pszParam, const CMyString& strParam){
    CMyString strResult(pszParam);
    strResult.Append(strParam.m_pszData);

    return strResult;
}

int main()
{
    CMyString b("World"), c;
    c = "Hello" + b;
    cout << (char*)c << endl;
    
    return 0;
}