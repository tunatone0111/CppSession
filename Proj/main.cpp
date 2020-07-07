#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
    CMyString strData;
    strData.SetString("Hello");
    strData.SetString("World");
    cout << strData.GetString() << endl;

    return 0;
}