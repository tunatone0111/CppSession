#include "headers/CMyIterator.h"

CMyNode* CMyIterator::GetCurrent() const{
    return m_pCurrent;
}

void CMyIterator::MoveNext(){
    if(m_pCurrent != NULL)
        m_pCurrent = m_pCurrent->GetNext();
}