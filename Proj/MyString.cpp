#include "MyString.h"
#include <iostream>
#include <string.h>

using namespace std;

CMyString::CMyString()
    : m_pszData(NULL),
      m_nLength(0)
{ }

CMyString::~CMyString(){
    Release(); 
}

CMyString::CMyString(const CMyString &rhs)
    : m_nLength(0),
      m_pszData(NULL)
{
    this->SetString(rhs.GetString());
}

CMyString& CMyString::operator=(const CMyString& rhs){
    if(this != &rhs){
        this->SetString(rhs.GetString());
    }
    return *this;
}

int CMyString::SetString(const char *pszParam){
    
    Release();

    if(pszParam == NULL){
        cout << "ERR: NULL pointer" << endl;
        return -1;
    }

    m_nLength = strlen(pszParam);
    
    if(m_nLength == 0){
        cout << "ERR: string length is 0" << endl;
        return -1;
    }

    m_pszData = new char[m_nLength];

    strcpy(m_pszData, pszParam);
    
    return m_nLength;
}

const char *CMyString::GetString() const{
    return m_pszData;
}

void CMyString::Release(){
    if (m_pszData != NULL)
        delete[] m_pszData;
    m_nLength = 0;
    m_pszData = NULL;
    return;
}