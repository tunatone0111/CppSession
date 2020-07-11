#include "headers/CUserInterface.h"
#include "headers/CMyList.h"
#include "headers/CUserData.h"
#include <iostream>
using namespace std;

CUserInterface::CUserInterface(CMyList &rList) 
    : m_List(rList)
{}

void CUserInterface::Add(){
    char szName[32] = {0};
    char szPhone[32] = {0};

    cout << "Input name: ";
    cin >> szName;

    cout << "Input phone number: ";
    cin >> szPhone;

    m_List.AddNewNode(new CUserData(szName, szPhone));
}

void CUserInterface::Search(){
    char szName[32] = {0};
    CUserData *pNode = NULL;

    cout << "Input name: ";
    cin >> szName;

    pNode = static_cast<CUserData*>(m_List.FindNode(szName));
    if(pNode != NULL)
        printf("[%p] %s\t%s [%p]\n", pNode, pNode->GetName(), pNode->GetPhone(), pNode->GetNext());
    else
        cout << "ERROR: 데이터를 찾을 수 없습니다." << endl;

    getchar();
    getchar();
}

void CUserInterface::Remove(){
    char szName[32] = {0};

    cout << "Input name: ";
    cin >> szName;

    m_List.RemoveNode(szName);
}

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
            PrintAll();
            break;

        case 4:
            Remove();
            break;
        }
    }
    return nMenu;
}

void CUserInterface::PrintAll(){
    CMyIterator it = m_List.MakeIterator();
    CMyNode *pTmp = NULL;

    while((pTmp = it.GetCurrent()) != NULL){
        static_cast<CUserData*>(pTmp)->PrintNode();
        it.MoveNext();
    }

    cout << "CUserData Counter: " << CUserData::GetUserDataCounter() << endl;

    getchar();
    getchar();
}

int CUserInterface::PrintUI(){
    int nInput = 0;

    system("clear");
    cout << "[1] Add\t [2] Search\t [3] Print all\t [4] Remove\t [0] Exit:" << endl << ":";

    cin >> nInput;

    return nInput;
}