#pragma once
#include "CMyNode.h"

class CMyIterator{
    friend class CMyList;

public:
    CMyIterator() = default;
    ~CMyIterator() = default;

    CMyNode* GetCurrent() const;

    void MoveNext();

private:
    CMyNode *m_pHead = nullptr;
    CMyNode *m_pCurrent = nullptr;
};