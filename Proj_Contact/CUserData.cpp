#include "headers/CUserData.h"
#include <iostream>
#include <string.h>
using namespace std;

int CUserData::nUserDataCounter = 0;

CUserData::CUserData(){
    nUserDataCounter++;
}

CUserData::CUserData(const char* pszName, const char* pszPhone)
{
    strName.SetString(pszName);
    strPhone.SetString(pszPhone);
    nUserDataCounter++;
}

CUserData::~CUserData(){
    nUserDataCounter--;
}

const char* CUserData::GetKey(){
    return GetName();
}

void CUserData::PrintNode(){
    printf("[%p] %s\t%s [%p]\n", this, GetName(), GetPhone(), GetNext());
}