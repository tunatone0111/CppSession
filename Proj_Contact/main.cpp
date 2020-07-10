#include <iostream>
#include "CMyList.h"
#include "CUserInterface.h"
using namespace std;

int main(){
    cout << "Hello World!" << endl;
    CMyList DB;
    CUserInterface UI(DB);
    UI.Run();
    return 0;
}