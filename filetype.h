#ifndef FILETYPE_H
#define FILETYPE_H

#include <stdio.h>


typedef enum SORT_TYPE {
    NAME,
    SIZE,
    COUNT
} SORT_TYPE_T;

typedef struct filetype {
    char * name;
    off_t size;
    int count;
} filetype_t;

extern const int MAX_FILETYPES;
extern filetype_t ** FILETYPES;
extern int lastFileTypeIndex;
extern size_t currentSize;
extern SORT_TYPE_T SORT_TYPE;


filetype_t * createFileType(char * name, int size, int count);
void insertFileType(filetype_t * ft);
void incrementSize(int index, int size);
void incrementCount(int index);
void sortByName();
void sortBySize();
void sortByCount();
int existsFileType(char * name);
void destroyFileType(FileType_t * ft);
void printFileType(FileType_t * ft);


#endif // FILETYPE_H



