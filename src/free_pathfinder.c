#include "pathfinder.h"

void free_pathfinder(t_pfinder *path) {
    // free(path->count);
    free(path);
    // if (path->lines)
    //     mx_del_strarr(&(path->lines));
}
