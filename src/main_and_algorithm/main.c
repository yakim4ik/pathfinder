#include "pathfinder.h"

int main (int argc, char *argv[]) {
    t_finder *path = (t_finder *)malloc(sizeof(t_finder));
    t_matrix *matrix = (t_matrix *)malloc(sizeof(t_matrix));

    mx_all_errors(argc, argv, path);
    mx_matrix_initialization(path, matrix);
    mx_floyd_warshall_algorithm(path, matrix);
    mx_output_results(path, matrix);
    mx_del_strarr(&path->uniq_isl);
    mx_del_strarr(&path->islands);
    mx_clean_memory_matrix(path, matrix);
    mx_clean_memory_path(path);
    return 0;
}
