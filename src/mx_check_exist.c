#include "pathfinder.h"

int mx_check_exist(int argc, char *argv[]) {
    int fd = 0;
    
    if(argc != 2) {
        mx_printerror("usage: ./pathfinder [filename]\n");
        exit(1);
    }
    if ((fd = open(argv[1], O_RDONLY)) <= 0) {
        mx_printerror("error: file ");
        mx_printerror(argv[1]);
        mx_printerror(" does not exist\n");
        exit(1);
    }
    return fd;
}
