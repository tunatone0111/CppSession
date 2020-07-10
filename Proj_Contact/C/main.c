#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myheader.h"

USERDATA g_Head = {0};

void main(){
    int nMenu = 0;
    LoadList(DATA_FILE_NAME);

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

    SaveList(DATA_FILE_NAME);
    ReleaseList();
}

USERDATA* FindNode(char* pszName){
    // 리스트에서 이름으로 특정 노드를 검색
    USERDATA *pTmp = g_Head.pNext;
    while(pTmp != NULL){
        if(strcmp(pTmp->szName, pszName) == 0)
            return pTmp;
        
        pTmp = pTmp->pNext;
    }
    return NULL;
}

int AddNewNode(char* pszName, char* pszPhone){
    USERDATA *pNewUser = NULL;

    if(FindNode(pszName) != NULL)
        return 0;

    pNewUser = (USERDATA*)calloc(1, sizeof(USERDATA));

    strcpy(pNewUser->szName, pszName);
    strcpy(pNewUser->szPhone, pszPhone);
    pNewUser->pNext = NULL;

    pNewUser->pNext = g_Head.pNext;
    g_Head.pNext = pNewUser;

    return 1;
}

void Add(){
    char szName[32] = {0};
    char szPhone[32] = {0};

    printf("Input name: ");
    fflush(stdin);
    scanf("%s", szName);

    printf("Input phone number: ");
    fflush(stdin);
    scanf("%s", szPhone);

    AddNewNode(szName, szPhone);
}

void Search(){
    char szName[32] = {0};
    USERDATA *pNode = NULL;

    printf("Input name: ");
    fflush(stdin);
    scanf("%s", szName);

    pNode = FindNode(szName);
    if(pNode != NULL)
        printf("[%p] %s\t%s [%p]\n", pNode, pNode->szName, pNode->szPhone, pNode->pNext);
    else
        puts("ERROR: 데이터를 찾을 수 없습니다.");

    getchar();
    getchar();
}

void PrintAll(){
    USERDATA *pTmp = g_Head.pNext;
    while(pTmp != NULL){
        printf("[%p] %s\t%s [%p]\n", pTmp, pTmp->szName, pTmp->szPhone, pTmp->pNext);
        pTmp = pTmp->pNext;
    }

    getchar();
    getchar();
}

int RemoveNode(char*pszName){
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

void Remove(){
    char szName[32] = {0};

    printf("Input name: ");
    fflush(stdin);
    scanf("%s", szName);

    RemoveNode(szName);
}

int PrintUI(){
    int nInput = 0;

    system("clear");
    printf("[1] Add\t [2] Search\t [3] Print all\t [4] Remove\t [0] Exit\n:");

    scanf("%d", &nInput);

    return nInput;
}

int LoadList(char*pszFileName){
    FILE *fp = NULL;
    USERDATA user = {0};

    if((fp = fopen(pszFileName, "rb")) == NULL)
        return 0;
    
    ReleaseList();

    while(fread(&user, sizeof(USERDATA), 1, fp))
        AddNewNode(user.szName, user.szPhone);

    fclose(fp);

    return 0;
}

int SaveList(char*pszFileName){
    FILE *fp = NULL;
    USERDATA *pTmp = g_Head.pNext;

    if((fp = fopen(pszFileName, "wb")) == NULL){
        puts("ERROR: 리스트 파일을 쓰기 모드로 열지 못했습니다.");
        fflush(stdin);
        getchar();
        return 0;
    }

    while(pTmp != NULL){
        if(fwrite(pTmp, sizeof(USERDATA), 1, fp) != 1)
            printf("ERROR: %s에 대한 정보를 저장하는 데 실패했습니다.\n", pTmp->szName);
        
        pTmp = pTmp->pNext;
    }

    fclose(fp);
    
    return 1;
}

void ReleaseList(){
    USERDATA *pTmp = g_Head.pNext;
    USERDATA *pDelete = NULL;

    while(pTmp != NULL){
        pDelete = pTmp;
        pTmp = pTmp->pNext;
        free(pDelete);
    }
    memset(&g_Head, 0x00, sizeof(USERDATA));
}