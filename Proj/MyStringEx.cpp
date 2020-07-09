#include "MyStringEx.h"
#include <string.h>

int CMyStringEx::Find(const char *pszParam){
    const char *temp = GetString();
    const char *strResult;
    if((strResult = strstr(temp, pszParam)) == NULL)
        return 0;
    return strResult-temp;
}