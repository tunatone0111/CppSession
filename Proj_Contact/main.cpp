#include <iostream>
#include "CMyList.h"
#include "CUserInterface.h"
#include "CUserData.h"
using namespace std;

int main(){
    CUserData pHead;
    CMyList DB(&pHead);
    CUserInterface UI(DB);
    UI.Run();
    return 0;
}