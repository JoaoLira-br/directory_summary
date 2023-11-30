
#define _DEFAULT_SOURCE

#include <stdio.h>
#include <string.h>

#include <dirent.h>

const char * ignorePath[] = {".", "..", ".git", NULL};

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