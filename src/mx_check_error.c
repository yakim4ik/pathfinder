#include "pathfinder.h"

void mx_check_error(int argc, char *argv[], t_pfinder *path) {
    int fd = mx_check_exist(argc, argv);
    char *str = mx_check_empty(fd, argv[1]);
    if (mx_check_line(str, path) || mx_split_file(str, path)) {
        free(str);
        mx_printstr("#####\n");
        system("leaks -q pathfinder");
        exit(1);
    }
    
    free(str);
}
