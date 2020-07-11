#pragma once
#include "MyString.h"
#include "CMyNode.h"

class CUserData : public CMyNode{

public:
    CUserData();
    CUserData(const char*, const char*);
    ~CUserData();

    const char* GetName() const{
        return strName.GetString();
    }

    const char* GetPhone() const{
        return strPhone.GetString();
    }

    static int GetUserDataCounter(){
        return nUserDataCounter;
    }

    const char* GetKey();
    void PrintNode();

protected:
    CMyString strName;
    CMyString strPhone;
    static int nUserDataCounter;

};