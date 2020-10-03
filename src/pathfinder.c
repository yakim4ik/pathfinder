#include "pathfinder.h"

int main(int argc, char *argv[]) {
    t_pfinder *path = NULL;

    mx_check_error(argc, argv, path);
    system("leaks -q pathfinder");
    return 0;
}
