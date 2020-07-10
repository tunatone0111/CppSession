#pragma once
#include "CUserData.h"
#define DATA_FILE_NAME "Address.dat"

class CMyList{
public:
    CMyList();
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