#include "dirinfo.h"

int main(int argc, char *argv[]) {
    struct dirinfo info;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if (get_dir_info(argv[1], &info) == -1) {
        perror("get_dir_info");
        exit(EXIT_FAILURE);
    }
    // printf("Total size: %ld\n", info.total_size);
    // printf("Number of files: %d\n", info.num_files);
    // printf("Number of directories: %d\n", info.num_subdirs);
    // free_dir_info(&info);
    return 0;
}