#include "pathfinder.h"

static int index_of_island(char *island, t_finder *path);
static void memory_for_matrices(t_finder *path, t_matrix *matrix);

void mx_matrix_initialization(t_finder *path, t_matrix *matrix) {
    int i;
    int j;
    char *buf = mx_strchr(path->file_in_str, ',');

    memory_for_matrices(path, matrix);
    for (i = 0; i < path->num_islands; i++) {
        for (j = 0; j < path->num_islands; j++) {
            matrix->table[i][j] = (i != j ? INT_MAX : 0);
        }
    }
    for (int ai = 0 ; (buf = mx_strchr(buf, ',')); ai +=2) {
        i = index_of_island(path->islands[ai], path);
        j = index_of_island(path->islands[ai + 1], path);
        matrix->table[i][j] = mx_atoi(++buf);
        matrix->table[j][i] = matrix->table[i][j];
    }
}

static void memory_for_matrices(t_finder *path, t_matrix *matrix) {
    matrix->table = (long **)malloc(sizeof(long *) * path->num_islands);
    matrix->first = (long **)malloc(sizeof(long *) * path->num_islands);
    for (int i = 0; i < path->num_islands; i++) {
        matrix->table[i] = (long *)malloc(sizeof(long) * path->num_islands);
        matrix->first[i] = (long *)malloc(sizeof(long) * path->num_islands);
    }
}

static int index_of_island(char *island, t_finder *path) {
    for (int i = 0; path->uniq_isl[i]; i++)
        if (!mx_strcmp(island, path->uniq_isl[i]))
            return i;
    return 0;
}
