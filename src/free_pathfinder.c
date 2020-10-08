#include "pathfinder.h"

void free_pathfinder(t_pfinder *path) {
    // char **del = path->islands;
    // if (path->line > 2)
    //     mx_printstr("islands\n");
    //     // free(path->islands);
    //     mx_del_strarr(&del);
    free(path);
}
