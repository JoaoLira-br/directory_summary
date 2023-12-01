
#define _DEFAULT_SOURCE

#include <stdio.h>
#include <string.h>

#include <dirent.h>

const char * ignorePath[] = {".", "..", ".git", NULL};

const char *get_filename_ext(const char *filename) {
    const char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}
int isIgnorePath(const char * path){
    int i = 0;
    while(ignorePath[i] != NULL){
        if(strcmp(ignorePath[i], path) == 0){
            return 1;
        }
        i++;
    }
    return 0;
}

void listFiles(const char* dirname) {
    DIR* dir = opendir(dirname);
    if (dir == NULL) {
        return;
    }

    printf("Reading files in: %s\n", dirname);
    
    struct dirent* entity;
    entity = readdir(dir);
    while (entity != NULL) {
        isIgnorePath(entity->d_name) ? printf("Ignore: ") : printf("Read: ");
        printf("extension %s\n", get_filename_ext(entity->d_name));
        printf("%hhd %s/%s\n", entity->d_type, dirname, entity->d_name);
        if (entity->d_type == DT_DIR && !isIgnorePath(entity->d_name) ) {
            char path[100] = { 0 };
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, entity->d_name);
            listFiles(path);
        }
        entity = readdir(dir);
    }

    closedir(dir);
}



int main(int argc, char* argv[]) {
    listFiles(".");
    return 0;
}