#pragma once
#include <iostream>
using namespace std;

class CMyNode{
    friend class CMyList;

public:
    CMyNode() = default;
    virtual ~CMyNode() = default;

    CMyNode* GetNext() const{
        return pNext;
    }

    virtual const char* GetKey() = 0;
    virtual void PrintNode() = 0;

private:
    CMyNode* pNext = nullptr;

};