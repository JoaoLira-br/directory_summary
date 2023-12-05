#include "dirinfo.h"

int main(int argc, char *argv[]) {
    struct dirinfo info;
    // if (argc != 2) {
    //     fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
    //     exit(EXIT_FAILURE);
    // }
    // printf("Directory: %s\n", argv[1]);
    const char * test = ".";
    if (get_dir_info(test, &info) == -1) {
        perror("get_dir_info");
        exit(EXIT_FAILURE);
    }else{
        print_dir_info(&info);
        free_dir_info(&info);
    }
    // printf("Total size: %ld\n", info.total_size);
    // printf("Number of files: %d\n", info.num_files);
    // printf("Number of directories: %d\n", info.num_subdirs);

    // free_dir_info(&info);
    return 0;
}