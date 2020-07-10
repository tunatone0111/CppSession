#pragma once

class CUserData{
    friend class CMyList;

public:
    CUserData() = default;
    ~CUserData() = default;

    const char* GetName() const{
        return szName;
    }

    const char* GetPhone() const{
        return szPhone;
    }

    const CUserData* GetNext() const{
        return pNext;
    }

    const int GetUserDataCounter(){
        return nUserDataCounter;
    }

protected:
    char szName[32] = {0};
    char szPhone[32] = {0};
    CUserData* pNext = nullptr;
    static int nUserDataCounter;

};