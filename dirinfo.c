
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


dirinfo_t * DIRINFO;

void initDirInfo() {
    DIRINFO = (dirinfo_t *) malloc(sizeof(dirinfo_t));
    DIRINFO->name = NULL;
    DIRINFO->total_size = 0;
    DIRINFO->num_files = 0;
    DIRINFO->num_subdirs = 0; 
    DIRINFO->largest_file = (fileinfo_t) {NULL, 0};
    DIRINFO->smallest_file = (fileinfo_t) {NULL, 0};
}



int file_count = 0;
int subdir_count = 0;
off_t total_size = 0;

int get_dir_info(const char *path, dirinfo_t *dirinfo) {
    initFileTypes(10);
    
    if(path == NULL || dirinfo == NULL || 
    strlen(path) == 0) {
        return -1;
    }
    struct stat statbuf;
    DIR *dir;
    struct dirent *entry;
   
    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        return -1;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            stat(entry->d_name, &statbuf);
            file_count++;
            off_t size = statbuf.st_size;
            total_size += size;

            const char * ext = get_filename_ext(entry->d_name);
            int index;
            if((index = existsFileType(ext)) != -1 ) {
                incrementSize(index, size);
                incrementCount(index);
            }
            else {
                filetype_t * ft = createFileType(ext, size);
                insertFileType(ft);
            }
        }
         if (entry->d_type == DT_DIR) {
            get_dir_info(entry->d_name, dirinfo);
            subdir_count++;
        }

    }

    closedir(dir);
    return file_count;
}
void print_dir_info(dirinfo_t *dir) {
    printf("Directory: %s\n", dir->name);
    printf("Total size: %ld\n", dir->total_size);
    printf("Number of files: %d\n", dir->num_files);
    printf("Number of subdirectories: %d\n", dir->num_subdirs);
    printf("Filetypes:\n");
    printFileTypes();
}
void free_dir_info(dirinfo_t *dir) {
    free(dir->name);
    free(dir);
}
