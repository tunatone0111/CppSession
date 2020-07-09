#include <iostream>
#include "MyStringEx.h"
using namespace std;

int main()
{
    CMyStringEx strLeft("Hello"), strRight("World");
    cout << (char*)(strLeft + strRight) << endl;

    return 0;
}