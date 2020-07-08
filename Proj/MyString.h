#pragma once

class CMyString
{
public:
    CMyString();
    CMyString(const CMyString&);                // copy constructor
    explicit CMyString(const char*);
    ~CMyString();

private:
    // 문자열을 저장하기 위해 동적 할당한 메모리를 가리키는 포인터
    char *m_pszData;

    //저장된 문자열의 길이
    int m_nLength;

public:
    int SetString(const char *pszParam);
    const char *GetString() const;
    void Release();
    CMyString& operator =(const CMyString&);    // operater overload
    operator char*() const {return m_pszData;}   // type cast

};