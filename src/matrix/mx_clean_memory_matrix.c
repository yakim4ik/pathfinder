#include "pathfinder.h"

static void del_int_arr(int **arr, t_finder *path) {
    if (arr) {
        for (int i = 0; i < path->num_islands; i++)
            free(arr[i]);
        free(arr);
    }
}

void mx_clean_memory_matrix(t_finder *path, t_matrix *matrix) {
    del_int_arr((int **)matrix->first, path);
    del_int_arr((int **)matrix->table, path);
    free(matrix);
}
