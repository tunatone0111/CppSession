#include "CMyList.h"
#include <iostream>
#include <string.h>
using namespace std;

CMyList::CMyList(const char* pszParam) : pszFileName(pszParam){
    FILE *fp = NULL;
    CUserData user;

    if ((fp = fopen(pszFileName, "rb")) != NULL){
        ReleaseList();

        while(fread(&user, sizeof(CUserData), 1, fp))
            AddNewNode(user.GetName(), user.GetPhone());

        fclose(fp);
    }
    cout << "ERROR: 리스트 파일을 읽기 모드로 열지 못했습니다." << endl;
}

CMyList::~CMyList(){
    FILE *fp = NULL;
    CUserData *pTmp = m_Head.GetNext();

    if((fp = fopen(pszFileName, "wb")) == NULL){
        puts("ERROR: 리스트 파일을 쓰기 모드로 열지 못했습니다.");
        fflush(stdin);
        getchar();
    }
    else{
        while(pTmp != NULL){
            if(fwrite(pTmp, sizeof(CUserData), 1, fp) != 1){
                printf("ERROR: %s에 대한 정보를 저장하는 데 실패했습니다.\n", pTmp->GetName());
                break;
            }
            pTmp = pTmp->GetNext();
        }
    }


    fclose(fp);
}

CUserData* CMyList::FindNode(const char* pszName){
    // 리스트에서 이름으로 특정 노드를 검색
    CUserData *pTmp = m_Head.GetNext();
    while(pTmp != NULL){
        if(strcmp(pTmp->GetPhone(), pszName) == 0)
            return pTmp;
        
        pTmp = pTmp->GetNext();
    }
    return NULL;
}

int CMyList::AddNewNode(const char* pszName, const char* pszPhone){
    CUserData *pNewUser = NULL;

    if(FindNode(pszName) != NULL)
        return 0;

    pNewUser = new CUserData;

    strcpy(pNewUser->szName, pszName);
    strcpy(pNewUser->szPhone, pszPhone);
    pNewUser->pNext = NULL;

    pNewUser->pNext = g_Head.pNext;
    g_Head.pNext = pNewUser;

    return 1;
}

void CMyList::PrintAll(){
    USERDATA *pTmp = g_Head.pNext;
    while(pTmp != NULL){
        printf("[%p] %s\t%s [%p]\n", pTmp, pTmp->szName, pTmp->szPhone, pTmp->pNext);
        pTmp = pTmp->pNext;
    }

    getchar();
    getchar();
}

int CMyList::RemoveNode(char*pszName){
    USERDATA *pPrevNode = &g_Head;
    USERDATA *pDelete = NULL;

    while(pPrevNode->pNext != NULL){
        pDelete = pPrevNode->pNext;

        if(strcmp(pDelete->szName, pszName) == 0){
            pPrevNode->pNext = pDelete->pNext;
            free(pDelete);
            return 1;
        }
        pPrevNode = pPrevNode->pNext;
    }
    return 0;
}

void CMyList::ReleaseList(){
    USERDATA *pTmp = g_Head.pNext;
    USERDATA *pDelete = NULL;

    while(pTmp != NULL){
        pDelete = pTmp;
        pTmp = pTmp->pNext;
        free(pDelete);
    }
    memset(&g_Head, 0x00, sizeof(USERDATA));
}