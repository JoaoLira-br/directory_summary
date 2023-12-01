
#define _DEFAULT_SOURCE

#include <dirent.h>
#include <stdio.h>
#include "dirinfo.h"
#include "filetype.h"
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
            off_t size = statbuf.st_size;
            char * ext = get_filename_ext(entry->d_name);
            file_count++;
            int index;
            if((index = existsFileType(ext)) != -1 ) {
                incrementSize(index, size);
                incrementCount(index);
            }
            else {
                createFileType(ext, size, 1);
            }
        }
        else if (entry->d_type == DT_DIR) {
            get_dir_info(entry->d_name, dirinfo);
            subdir_count++;
        }

    }

    closedir(dir);
    return file_count;
}
void print_dir_info(dirinfo_t *dir) {
    printf("Directory: %s\n", dir->name);
    printf("Total size: %d\n", dir->total_size);
    printf("Number of files: %d\n", dir->num_files);
    printf("Number of subdirectories: %d\n", dir->num_subdirs);
    printf("Filetypes:\n");
    for (int i = 0; i < MAX_FILETYPES; i++) {
        printFileType(FILETYPES[i]);
    }
}
void free_dir_info(dirinfo_t *dir) {
    free(dir->name);
    free(dir);
}
