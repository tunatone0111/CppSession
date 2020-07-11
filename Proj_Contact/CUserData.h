#pragma once
#include "CMyNode.h"

class CUserData : public CMyNode{

public:
    CUserData();
    CUserData(const char*, const char*);
    ~CUserData();

    const char* GetName() const{
        return szName;
    }

    const char* GetPhone() const{
        return szPhone;
    }

    static int GetUserDataCounter(){
        return nUserDataCounter;
    }

    const char* GetKey();
    void PrintNode();

protected:
    char szName[32] = {0};
    char szPhone[32] = {0};
    static int nUserDataCounter;

};