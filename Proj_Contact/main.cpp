#include <iostream>
#include "headers/CMyList.h"
#include "headers/CUserInterface.h"
#include "headers/CUserData.h"
using namespace std;

int main(){
    CUserData pHead;
    CMyList DB(&pHead);
    CUserInterface UI(DB);
    UI.Run();
    return 0;
}