#ifndef MY_HEADER
#define MY_HEADER

#define DATA_FILE_NAME "Address.dat"

void ReleaseList();

typedef struct _USERDATA{
    char szName[32];
    char szPhone[32];

    struct _USERDATA *pNext;
} USERDATA;

USERDATA* FindNode(char*);
int AddNewNode(char*, char*);
void Add();
void Search();
void PrintAll();
int RemoveNode(char*);
void Remove();
int PrintUI();
int LoadListr(char*);
int SaveList(char*);
void ReleaseList();

#endif