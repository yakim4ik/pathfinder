#pragma once

#include "libmx.h"

#define INT_MAX 2147483647

typedef struct s_finder {
    int fd;
    int words;
    int num_islands;
    char *file_in_str;
    char **uniq_isl;
    char **islands;
}              t_finder;

typedef struct s_matrix {
    int len;
    int *route;
    long **first;
    long **table;
}              t_matrix;

/*
 *   VALIDATION OF ERRORS
 */
void mx_all_errors(int argc, char *argv[], t_finder *path);
void mx_empty_file(char *argv[], t_finder *path);
void mx_wrong_args_or_file(int argc, char *argv[], t_finder *path);
void mx_invalid_line(t_finder *path);
void mx_invalid_num_or_double_of_islands(t_finder *path);
void mx_print_invalid_line(int line, t_finder *path);
void mx_invalid_bridges_lenght(t_finder *path);

/*
 *   ALGORITHM
 */
void mx_matrix_initialization(t_finder *path, t_matrix *matrix);
void mx_floyd_warshall_algorithm(t_finder *path, t_matrix *matrix);

/*
 *   RESULTS AND CLEANING
 */
void mx_print_boundary();
void mx_output_results(t_finder *path, t_matrix *matrix);
void mx_clean_memory_path(t_finder *path);
void mx_clean_memory_matrix(t_finder *path, t_matrix *matrix);
