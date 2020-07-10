#pragma once
#include "CUserData.h"

class CMyList{
public:
    CMyList() = default;
    ~CMyList() = default;

    CUserData* FindNode(const char*);
    int AddNewNode(const char*, const char*);

    void PrintAll();

    int RemoveNode(const char*);

protected:
    void ReleaseList(void);
    CUserData m_Head;

};