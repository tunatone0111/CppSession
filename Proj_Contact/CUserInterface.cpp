#include "CUserInterface.h"
#include "CMyList.h"
#include <iostream>

CUserInterface::CUserInterface(CMyList &rList) 
    : m_List(rList)
{}

void CUserInterface::Add(){
    char szName[32] = {0};
    char szPhone[32] = {0};

    printf("Input name: ");
    fflush(stdin);
    scanf("%s", szName);

    printf("Input phone number: ");
    fflush(stdin);
    scanf("%s", szPhone);

    m_List.AddNewNode(szName, szPhone);
}

void CUserInterface::Search(){
    char szName[32] = {0};
    CUserData *pNode = NULL;

    printf("Input name: ");
    fflush(stdin);
    scanf("%s", szName);

    pNode = m_List.FindNode(szName);
    if(pNode != NULL)
        printf("[%p] %s\t%s [%p]\n", pNode, pNode->GetName(), pNode->GetPhone(), pNode->GetNext());
    else
        puts("ERROR: 데이터를 찾을 수 없습니다.");

    getchar();
    getchar();
}

void CUserInterface::Remove(){
    char szName[32] = {0};

    printf("Input name: ");
    fflush(stdin);
    scanf("%s", szName);

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
            m_List.PrintAll();
            break;

        case 4:
            Remove();
            break;
        }
    }
    return nMenu;
}

int CUserInterface::PrintUI(){
    int nInput = 0;

    system("clear");
    printf("[1] Add\t [2] Search\t [3] Print all\t [4] Remove\t [0] Exit\n:");

    scanf("%d", &nInput);

    return nInput;
}