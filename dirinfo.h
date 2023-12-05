#ifndef DIRINFO_H
#define DIRINFO_H

#include "sys/stat.h"
#include "sys/types.h"
#include "dirent.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
#include "errno.h"
#include "locale.h"
#include "filetype.h"



// Path: directory_summary/structs/dirinfo.h
typedef struct fileinfo {
    char *name;
    int size;
} fileinfo_t;

typedef struct dirinfo {
    char *name;
    long total_size;
    int num_files;
    int num_subdirs;
    fileinfo_t largest_file;
    fileinfo_t smallest_file;
    

} dirinfo_t;



extern dirinfo_t * DIRINFO;

// Path: directory_summary/structs/dirinfo.h
void initDirInfo();
int get_dir_info(const char *path, dirinfo_t *dirinfo);
void print_dir_info(dirinfo_t *dir);
void free_dir_info(dirinfo_t *dir);

#endif // !DIR



