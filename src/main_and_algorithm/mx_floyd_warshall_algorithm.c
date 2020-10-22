#include "pathfinder.h"

void mx_floyd_warshall_algorithm(t_finder *path, t_matrix *matrix) {
    long sum;
    int i;

    for (i = 0; i < path->num_islands; i++) { // duplicate 1st table
        for (int j = i; j < path->num_islands; j++) {
            matrix->first[i][j] = matrix->table[i][j];
            matrix->first[j][i] = matrix->table[j][i];
        }
    }
    for (int k = 0; k < path->num_islands; k++) {
        for (i = 0; i < path->num_islands; i++) {
            for (int j = i + 1; j < path->num_islands; j++) {
                sum = matrix->table[k][j] + matrix->table[i][k];
                if (matrix->table[i][j] > sum) {
                    matrix->table[i][j] = sum;
                    matrix->table[j][i] = sum;
                }
            }
        }
    }
}
