#include "MyString.h"
#include <iostream>
#include <string.h>

using namespace std;

CMyString::CMyString()
    : m_pszData(NULL),
      m_nLength(0)
{
}

CMyString::~CMyString(){
    Release(); 
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
    
    for(int i = 0; i < m_nLength; i++){
        m_pszData[i] = pszParam[i];
    }
    
    m_pszData[m_nLength] = '\0';
    
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