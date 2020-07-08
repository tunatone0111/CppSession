#pragma once

class CMyString
{
public:
    //디폴트 생성자
    CMyString();

    //복사 생성자
    CMyString(const CMyString&);
    
    //이동 생성자
    CMyString(CMyString&&);
    
    //변환 생성자
    CMyString(const char*);
    
    //소멸자
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
    CMyString& operator =(CMyString&&);
    explicit operator char*() const {return m_pszData;}   // type cast
    int GetLength() const { return m_nLength;}
    int Append(const char *);

    CMyString operator+(const CMyString&);
    CMyString& operator+=(const CMyString&);
    char& operator[](int);
    char operator[](int) const;
    int operator==(const CMyString&);
    int operator!=(const CMyString&);
};