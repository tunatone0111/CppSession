#include <iostream>
#include "CMyList.h"
#include "CUserInterface.h"
#define DATA_FILE_NAME "Address.dat"
using namespace std;

int main(){
    cout << "Hello World!" << endl;
    CMyList DB(DATA_FILE_NAME);
    CUserInterface UI(DB);
    UI.Run();
    return 0;
}