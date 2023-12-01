#include "filetype.h"
#include "stdlib.h"
#include "string.h"

// Path: directory_summary/structs/filetype.c

filetype_t ** FILETYPES;  // array of pointers to filetypes
int lastFileTypeIndex = 0; // index of last filetype in FILETYPES
size_t currentSize = 0; // current size of FILETYPES

// Function to initialize FILETYPES with an initial size
void initFILETYPES(size_t initialSize) {
    currentSize = initialSize * sizeof(filetype_t *);
    
    FILETYPES = malloc(initialSize * sizeof(filetype_t *));
    if (FILETYPES == NULL) {
        // Handle memory allocation failure
        perror("malloc failed");
    }
    while(lastFileTypeIndex < initialSize) {
        FILETYPES[lastFileTypeIndex] = NULL;
        lastFileTypeIndex++;
    }
    // Initialize elements to NULL or initial values
}
void reallocFILETYPES() {
    currentSize *= 2;

    FILETYPES = realloc(FILETYPES, sizeof(FILETYPES) * 2);
    if (FILETYPES == NULL) {
        // Handle memory allocation failure
        perror("realloc failed");
    }
    while(lastFileTypeIndex < currentSize) {
        FILETYPES[lastFileTypeIndex] = NULL;
        lastFileTypeIndex++;            
    }
}

void insertFileType(filetype_t * ft) {

    if () {
        reallocFILETYPES();
    }
    FILETYPES[size] = ft;
}
filetype_t * createFileType(char * name, int size, int count) {
    filetype_t * ft = (filetype_t *) malloc(sizeof(filetype_t));
    ft->name = name;
    ft->size = size;
    ft->count = count;
    return ft;
}

int compareFileTypeByName(const void * a, const void * b) {
    filetype_t * ft1 = (filetype_t *) a;
    filetype_t * ft2 = (filetype_t *) b;
    return strcmp(ft1->name, ft2->name);
}

int compareFileTypeBySize(const void * a, const void * b) {
    filetype_t * ft1 = (filetype_t *) a;
    filetype_t * ft2 = (filetype_t *) b;
    return ft1->size - ft2->size;
}

int compareFileTypeByCount(const void * a, const void * b) {
    filetype_t * ft1 = (filetype_t *) a;
    filetype_t * ft2 = (filetype_t *) b;
    return ft1->count - ft2->count;
}

void sortByName() {
    qsort(*FILETYPES, sizeof(FILETYPES), sizeof(filetype_t), compareFileTypeByName);
    SORT_TYPE = NAME;
}
void sortBySize() {
    qsort(*FILETYPES, sizeof(FILETYPES), sizeof(filetype_t), compareFileTypeBySize);
    SORT_TYPE = SIZE;
}
void sortByCount() {
    qsort(*FILETYPES, sizeof(FILETYPES), sizeof(filetype_t), compareFileTypeByCount);
    SORT_TYPE = COUNT;
}

void destroyFileType(filetype_t * ft) {
    free(ft->name);
    free(ft);
}

void printFileType(filetype_t * ft) {
    printf("Filetype: %s\n", ft->name);
    printf("Size: %d\n", ft->size);
    printf("Count: %d\n", ft->count);
}

/*
if the filetype existsFileType, return the index of the filetype in FILETYPES
else return NULL
*/
int existsFileType(char * name){
    int size = sizeof(FILETYPES) / sizeof(filetype_t *);
    for (int i = 0; i < size; i++) {
        if (strcmp(FILETYPES[i]->name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void incrementSize(int index, int size) {
    filetype_t * ft = FILETYPES[index];

    ft->size += size;
}
void incrementCount(int index) {
    filetype_t * ft = FILETYPES[index];

    ft->count++;
}

void printFileTypes() {
    int size = sizeof(FILETYPES) / sizeof(filetype_t *);
    for (int i = 0; i < size; i++) {
        printf("Filetype: %s\n", FILETYPES[i]->name);
        printf("Size: %d\n", FILETYPES[i]->size);
        printf("Count: %d\n", FILETYPES[i]->count);
    }
}

void freeFileTypes() {
    int size = sizeof(FILETYPES) / sizeof(filetype_t *);
    for (int i = 0; i < size; i++) {
        free(FILETYPES[i]->name);
        free(FILETYPES[i]);
    }
}




