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

extern filetype_t ** FILETYPES;
extern int lastFileTypeIndex;
extern size_t currentSize;
extern SORT_TYPE_T sort_type;

void initFileTypes(size_t initialSize);
filetype_t * createFileType( const char * name, int size);
void insertFileType(filetype_t * ft);
void incrementSize(int index, int size);
void incrementCount(int index);
void sortByName();
void sortBySize();
void sortByCount();
int existsFileType(const char * name);
void freeFileTypes();
void printFileTypes();


#endif // FILETYPE_H



