#pragma once

class CMyList;

class CUserInterface{
public:
    CUserInterface(CMyList &rList);
    ~CUserInterface() = default;
    
    void Add();
    void Search();
    void Remove();
    int PrintUI();
    int Run();

protected:
    CMyList& m_List;
};