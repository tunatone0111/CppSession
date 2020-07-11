#pragma once
#include "CMyNode.h"
#include "CMyIterator.h"
#define DATA_FILE_NAME "Address.dat"

class CMyList{
public:
    CMyList(CMyNode*);
    ~CMyList();

    CMyNode* FindNode(const char*);
    int AddNewNode(CMyNode*);

    int RemoveNode(const char*);

    CMyIterator MakeIterator();

    virtual int OnAddNewNode(CMyNode*);

protected:
    void ReleaseList(void);
    CMyNode* m_pHead;
};