#include "CMyList.h"
#include "CUserData.h"
#include <iostream>
#include <string.h>
using namespace std;

CMyList::CMyList(CMyNode *pHead) : m_pHead(pHead){
    FILE *fp = NULL;
    CUserData user;

    if((fp = fopen(DATA_FILE_NAME, "rb")) == NULL)
        cout << "ERROR: 리스트 파일을 쓰기 모드로 열지 못했습니다." << endl;
    else{
        ReleaseList();

        while(fread(&user, sizeof(CUserData), 1, fp))
            AddNewNode(new CUserData(user.GetName(), user.GetPhone()));

        fclose(fp);
    }
}

CMyList::~CMyList(){
    FILE *fp = NULL;
    CMyNode *pTmp = m_pHead->pNext;

    if((fp = fopen(DATA_FILE_NAME, "wb")) == NULL){
        cout << "ERROR: 리스트 파일을 쓰기 모드로 열지 못했습니다." << endl;
        fflush(stdin);
        getchar();
    }
    else{
        while(pTmp != NULL){
            if(fwrite(pTmp, sizeof(CUserData), 1, fp) != 1){
                cout << "ERROR: " << pTmp->GetKey() << "에 대한 정보를 저장하는 데 실패했습니다."  << endl;
                break;
            }
            pTmp = pTmp->pNext;
        }
    }

    fclose(fp);

    ReleaseList();
}

CMyNode* CMyList::FindNode(const char* pszKey){
    // 리스트에서 이름으로 특정 노드를 검색
    CMyNode *pTmp = m_pHead->pNext;
    while(pTmp != NULL){
        if(strcmp(pTmp->GetKey(), pszKey) == 0)
            return pTmp;
        
        pTmp = pTmp->pNext;
    }
    return NULL;
}

int CMyList::AddNewNode(CMyNode *pNewNode){
    if(FindNode(pNewNode->GetKey()) != NULL){
        delete pNewNode;
        return 0;
    }

    pNewNode->pNext = m_pHead->pNext;
    m_pHead->pNext = pNewNode;

    return 1;
}

void CMyList::PrintAll(){
    CMyNode *pTmp = m_pHead->pNext;

    while(pTmp != NULL){
        pTmp->PrintNode();
        pTmp = pTmp->pNext;
    }

    getchar();
    getchar();
}

int CMyList::RemoveNode(const char* pszKey){
    CMyNode *pPrevNode = m_pHead;
    CMyNode *pDelete = NULL;

    while(pPrevNode->pNext != NULL){
        pDelete = pPrevNode->pNext;

        if(strcmp(pDelete->GetKey(), pszKey) == 0){
            pPrevNode->pNext = pDelete->pNext;
            free(pDelete);
            return 1;
        }
        pPrevNode = pPrevNode->pNext;
    }
    return 0;
}

void CMyList::ReleaseList(){
    CMyNode *pTmp = m_pHead->pNext;
    CMyNode *pDelete = NULL;

    while(pTmp != NULL){
        pDelete = pTmp;
        pTmp = pTmp->pNext;
        delete pDelete;
    }
    memset(m_pHead, 0x00, sizeof(CUserData));
}