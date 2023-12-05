#include "filetype.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"





// Path: directory_summary/structs/filetype.c

filetype_t ** FILETYPES;  // array of pointers to filetypes
SORT_TYPE_T sort_type;
int lastFileTypeIndex = 0; // index of last filetype in FILETYPES
size_t currentSize = 0; // current size of FILETYPES


void initFileTypes(size_t initialSize) {
    currentSize = initialSize;
    FILETYPES = (filetype_t **)malloc(initialSize * sizeof(filetype_t *));
    if (FILETYPES == NULL) {
        perror("malloc failed");
        exit(EXIT_FAILURE); // Exit if allocation fails
    }
    for (size_t i = 0; i < initialSize; i++) {
        FILETYPES[i] = NULL;
    }
}
// Function to double the size of FILETYPES
void reallocFILETYPES() {
    size_t newSize = currentSize * 2;
    filetype_t **temp = (filetype_t **)realloc(FILETYPES, newSize * sizeof(filetype_t *));
    if (temp == NULL) {
        perror("realloc failed");
        exit(EXIT_FAILURE); // Exit if reallocation fails
    }
    FILETYPES = temp;
    for (size_t i = currentSize; i < newSize; i++) {
        FILETYPES[i] = NULL;
    }
    currentSize = newSize;
}

// Function to insert a new filetype
void insertFileType(filetype_t * ft) {
    if (lastFileTypeIndex >= currentSize) {
        reallocFILETYPES();
    }
    FILETYPES[lastFileTypeIndex++] = ft;
}

// ... [other parts of the code] ...

filetype_t * createFileType( const char * name, int size) {
    filetype_t * ft = (filetype_t *) malloc(sizeof(filetype_t));
    ft->name =  strdup(name);
    ft->size = size;
    ft->count = 1;
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
    qsort(*FILETYPES, currentSize, sizeof(filetype_t *), compareFileTypeByName);
    sort_type = NAME;
}
void sortBySize() {
    qsort(*FILETYPES, currentSize, sizeof(filetype_t *), compareFileTypeBySize);
    sort_type = SIZE;
}
void sortByCount() {
    qsort(*FILETYPES, currentSize, sizeof(filetype_t *), compareFileTypeByCount);
    sort_type = COUNT;
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
    size_t i;
    for (i = 0; i <= lastFileTypeIndex; i++) {
        if (FILETYPES[i] != NULL) {
            printf("Filetype: %s\n", FILETYPES[i]->name);
            printf("Size: %ld\n", FILETYPES[i]->size);
            printf("Count: %d\n", FILETYPES[i]->count);
        }
    }
}


void freeFileTypes() {
    size_t i;
    for (i = 0; i <= lastFileTypeIndex; i++) {
        if(FILETYPES[i] != NULL) {
            free(FILETYPES[i]->name);
            free(FILETYPES[i]);
        }
        
    }
}

/*
if the filetype existsFileType, return the index of the filetype in FILETYPES
else return -1
*/
int existsFileType(const char * name){
    size_t i;
    for ( i = 0; i <= lastFileTypeIndex; i++) {
        if (FILETYPES[i] != NULL && strcmp(FILETYPES[i]->name, name) == 0) {
            return i;
        }
    }
    return -1;
}




// ... [other parts of the code] ...

// Function to initialize FILETYPES with an initial size




