#include "pathfinder.h"

char *mx_check_empty(int fd, char *argv) {
    int temp;
    char c;

     if ((temp = read(fd, &c, 1) == 0)) {
        mx_printerror("error: file ");
        mx_printerror(argv);
        mx_printerror(" is empty\n");
        close(fd);
        exit(1);
    }
    close(fd);
    return mx_file_to_str(argv); 
}
