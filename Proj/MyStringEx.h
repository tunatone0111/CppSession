#pragma once
#include "MyString.h"

class CMyStringEx : public CMyString{
public:
    CMyStringEx() = default;
    ~CMyStringEx() = default;
    int Find(const char*);
    int SetString(const char*);
};