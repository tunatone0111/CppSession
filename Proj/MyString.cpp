#include "MyString.h"
#include <iostream>
#include <string.h>

using namespace std;

CMyString::CMyString()
    : m_pszData(NULL),
      m_nLength(0)
{}

CMyString::~CMyString(){
    Release(); 
}

CMyString::CMyString(const CMyString &rhs)
    : m_nLength(0),
      m_pszData(NULL)
{
    this->SetString(rhs.GetString());
}

CMyString::CMyString(const char *rhs) 
    : m_nLength(0), 
      m_pszData(NULL)
{
    this->SetString(rhs);
}

CMyString::CMyString(CMyString &&rhs)
    : m_nLength(0),
      m_pszData(NULL)
{
    cout << "이동 생성자 호출" << endl;
    m_nLength = rhs.m_nLength;
    m_pszData = rhs.m_pszData;
    rhs.m_pszData = NULL;
    rhs.m_nLength = 0;
}

CMyString& CMyString::operator=(const CMyString& rhs){
    if(this != &rhs){
        this->SetString(rhs.GetString());
    }
    return *this;
}

CMyString& CMyString::operator=(CMyString &&rhs){
    cout << "이동 대입 연산자 호출" << endl;
    m_nLength = rhs.m_nLength;
    m_pszData = rhs.m_pszData;
    rhs.m_pszData = NULL;
    rhs.m_nLength = 0;
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

int CMyString::Append(const char *pszParam){
    if(pszParam == NULL) return 0;

    int nLenParam = strlen(pszParam);

    if(nLenParam == 0) return 0;

    if(m_pszData == NULL){
        SetString(pszParam);
        return m_nLength;
    }

    int nLenCur = m_nLength;
    char *pszResult = new char[nLenCur+nLenParam+1];

    strcpy(pszResult, m_pszData);
    strcpy(pszResult+nLenCur, pszParam);
    
    Release();
    m_pszData = pszResult;
    m_nLength = nLenCur+nLenParam;

    return m_nLength;
}

CMyString CMyString::operator+(const CMyString &rhs){
    CMyString Result(m_pszData);
    Result.Append(rhs.GetString());
    return Result;
}

CMyString& CMyString::operator+=(const CMyString &rhs){
    Append(rhs.GetString());
    return *this;
}

char& CMyString::operator[](int nIndex){
    if(nIndex<0 || nIndex>m_nLength){
        cout << "unavailable" << endl;
        return m_pszData[0];
    }
    return m_pszData[nIndex];
}

char CMyString::operator[](int nIndex) const{
    if(nIndex<0 || nIndex>m_nLength){
        cout << "unavailable" << endl;
        return m_pszData[0];
    }
    return m_pszData[nIndex];
}

int CMyString::operator==(const CMyString &rhs){
    if(m_pszData != NULL && rhs.m_pszData != NULL){
        if(strcmp(m_pszData, rhs.m_pszData) == 0){
            return 1;
        }
    }
    return 0;
}

int CMyString::operator!=(const CMyString &rhs){
    if(m_pszData != NULL && rhs.m_pszData != NULL){
        if(strcmp(m_pszData, rhs.m_pszData) == 0){
            return 0;
        }
    }
    return 1;
}


void CMyString::Release(){
    if (m_pszData != NULL)
        delete[] m_pszData;
    m_nLength = 0;
    m_pszData = NULL;
    return;
}