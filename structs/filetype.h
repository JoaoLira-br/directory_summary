#ifndef FILETYPE_H

#define FILETYPE_H

#include <iostream>
#include <string>




typedef struct FileType {
    char * name;
    int size;
    int count;
} Filetype_t;

extern const int MAX_FILETYPES;
extern const int MAX_FILETYPE_NAME_LENGTH;
extern const int MAX_FILETYPE_COUNT;
extern Filetype_t * FILETYPES[];

Filetype_t * createFileType(char * name, int size, int count);
void sortByName();
void sortBySize();
void sortByCount();
void destroyFileType(FileType * ft);
void printFileType(FileType * ft);


#endif // FILETYPE_H



