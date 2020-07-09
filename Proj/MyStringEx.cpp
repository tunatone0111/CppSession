#include "MyStringEx.h"
#include <string.h>

int CMyStringEx::Find(const char *pszParam){
    const char *temp = GetString();
    const char *strResult;
    if((strResult = strstr(temp, pszParam)) == NULL)
        return 0;
    return strResult-temp;
}

void CMyStringEx::OnSetString(char* pszData, int nLength){
    if(strcmp(pszData, "멍멍이아들") == 0)
        strcpy(pszData, "*착한아들");
}