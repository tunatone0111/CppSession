#pragma once
#include "CMyNode.h"
#define DATA_FILE_NAME "Address.dat"

class CMyList{
public:
    CMyList(CMyNode*);
    ~CMyList();

    CMyNode* FindNode(const char*);
    int AddNewNode(CMyNode*);

    void PrintAll();

    int RemoveNode(const char*);

protected:
    void ReleaseList(void);
    CMyNode* m_pHead;
};