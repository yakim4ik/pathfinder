#include "pathfinder.h"

void mx_clean_memory_path(t_finder *path) {
    if (path->file_in_str)
        mx_strdel(&path->file_in_str);
    free(path);
}
