#include "pathfinder.h"

void mx_all_errors(int argc, char *argv[], t_finder *path) {
    mx_wrong_args_or_file(argc, argv, path);
    mx_empty_file(argv, path);
    mx_invalid_line(path);
    mx_invalid_num_or_double_of_islands(path);
    mx_invalid_bridges_lenght(path);
}
