#pragma once
#include "CUserData.h"

class CMyList{
public:
    CMyList(const char*);
    ~CMyList();

    CUserData* FindNode(const char*);
    int AddNewNode(const char*, const char*);

    void PrintAll();

    int RemoveNode(const char*);

protected:
    void ReleaseList(void);
    CUserData m_Head;

private:
    const char *pszFileName;

};