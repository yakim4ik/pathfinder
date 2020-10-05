#include "pathfinder.h"

bool mx_print_error_line (int line, t_pfinder *path) {
    mx_printerror("error: line ");
    mx_printerror_int(line);
    mx_printerror(" is not valid\n");
    free_pathfinder(path);
    return true;
}
