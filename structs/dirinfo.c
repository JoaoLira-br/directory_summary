
#define _DEFAULT_SOURCE

#include <dirent.h>
#include <stdio.h>
#include "dirinfo.h"
#include <sys/stat.h>

const char *get_filename_ext(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}

int get_dir_info(const char *path, dirinfo_t *dirinfo) {

    if(path == NULL || dirinfo == NULL || 
    strlen(path) == 0) {
        return -1;
    }
    struct stat statbuf;
    
    DIR *dir;
    struct dirent *entry;
    int file_count = 0;
    int subdir_count = 0;


    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            stat(entry->d_name, &statbuf);
            file_count++;
        }
        else if (entry->d_type == DT_DIR) {
            stat(entry->d_name, &statbuf);
            subdir_count++;
        }

    }

    closedir(dir);
    return file_count;
}