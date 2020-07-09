#include "MyStringEx.h"
#include <string.h>

int CMyStringEx::Find(const char *pszParam){
    const char *temp = GetString();
    const char *strResult;
    if((strResult = strstr(temp, pszParam)) == NULL)
        return -1;
    return strResult-temp;
}

int CMyStringEx::SetString(const char *pszParam){
    if(pszParam == NULL) return 0;
    
    if(strcmp(pszParam, "멍멍이아들") == 0){
        return CMyString::SetString("착한 사람");
    }
    else{
        return CMyString::SetString(pszParam);
    }
}