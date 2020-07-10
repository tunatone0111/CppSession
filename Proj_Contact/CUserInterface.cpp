#include "CUserInterface.h"
#include <iostream>

CUserInterface::CUserInterface(CMyList &rList) 
    : m_List(rList)
{}

int CUserInterface::Run(){
    int nMenu = 0;

    while((nMenu = PrintUI()) != 0){
        switch(nMenu){
        case 1:
            Add();
            break;

        case 2:
            Search();
            break;

        case 3:
            // PrintAll();
            break;

        case 4:
            Remove();
            break;
        }
    }
    return nMenu;
}