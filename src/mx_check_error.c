#include "pathfinder.h"

void mx_check_error(int argc, char *argv[], t_pfinder *path) {
    int fd = mx_check_exist(argc, argv);
    char *str = mx_check_empty(fd, argv[1]);

    mx_check_line(str);

    free(str);
    if (path)
        mx_printstr("DIMA");
}
