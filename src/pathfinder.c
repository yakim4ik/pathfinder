#include "pathfinder.h"

int main(int argc, char *argv[]) {
    t_pfinder *path = NULL;

    path = init_pathfinder(path);
    mx_check_error(argc, argv, path);
    free_pathfinder(path);
    
    mx_printstr("\nmain.c");
    system("leaks -q pathfinder");
    return 0;
}
