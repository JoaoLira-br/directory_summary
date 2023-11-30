#include "filetype.h"

// Path: directory_summary/structs/filetype.c


Filetype_t * createFileType(char * name, int size, int count) {
    Filetype_t * ft = (Filetype_t *) malloc(sizeof(Filetype_t));
    ft->name = name;
    ft->size = size;
    ft->count = count;
    return ft;
}

todo: implement these functions, along with helper comparison functions using qsort
void sortByName() {

}
void sortBySize() {

}
void sortByCount() {

}

void destroyFileType(FileType * ft) {
    free(ft->name);
    free(ft);
}

void printFileType(FileType * ft) {
    printf("Filetype: %s\n", ft->name);
    printf("Size: %d\n", ft->size);
    printf("Count: %d\n", ft->count);
}


