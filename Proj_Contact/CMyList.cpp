#include "CMyList.h"
#include <iostream>
#include <string.h>
using namespace std;

CMyList::CMyList(){
    FILE *fp = NULL;
    CUserData user;

    if ((fp = fopen(DATA_FILE_NAME, "rb")) != NULL){
        ReleaseList();

        while(fread(&user, sizeof(CUserData), 1, fp))
            AddNewNode(user.GetName(), user.GetPhone());

        fclose(fp);
    }
    else{
    cout << "ERROR: 리스트 파일을 읽기 모드로 열지 못했습니다." << endl;
    }
}

CMyList::~CMyList(){
    FILE *fp = NULL;
    CUserData *pTmp = m_Head.pNext;

    if((fp = fopen(DATA_FILE_NAME, "wb")) == NULL){
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
            pTmp = pTmp->pNext;
        }
    }

    fclose(fp);

    ReleaseList();
}

CUserData* CMyList::FindNode(const char* pszName){
    // 리스트에서 이름으로 특정 노드를 검색
    CUserData *pTmp = m_Head.pNext;
    while(pTmp != NULL){
        if(strcmp(pTmp->GetName(), pszName) == 0)
            return pTmp;
        
        pTmp = pTmp->pNext;
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

    pNewUser->pNext = m_Head.pNext;
    m_Head.pNext = pNewUser;

    return 1;
}

void CMyList::PrintAll(){
    CUserData *pTmp = m_Head.pNext;
    while(pTmp != NULL){
        printf("[%p] %s\t%s [%p]\n", pTmp, pTmp->szName, pTmp->szPhone, pTmp->pNext);
        pTmp = pTmp->pNext;
    }

    getchar();
    getchar();
}

int CMyList::RemoveNode(const char* pszName){
    CUserData *pPrevNode = &m_Head;
    CUserData *pDelete = NULL;

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
    CUserData *pTmp = m_Head.pNext;
    CUserData *pDelete = NULL;

    while(pTmp != NULL){
        pDelete = pTmp;
        pTmp = pTmp->pNext;
        free(pDelete);
    }
    memset(&m_Head, 0x00, sizeof(CUserData));
}