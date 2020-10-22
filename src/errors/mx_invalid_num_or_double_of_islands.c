#include "pathfinder.h"

static void unique_islands(t_finder *path);
static void double_islands(t_finder *path);
static void duplicate_bridges(t_finder *path);

static void print_invalid_number(t_finder *path) {
    mx_printerr("error: invalid number of islands\n");
    mx_clean_memory_path(path);
    exit(1);
}

void mx_invalid_num_or_double_of_islands(t_finder *path) {
    char *buf = mx_strdup(path->file_in_str);

    path->num_islands = mx_atoi(buf);
    if (path->num_islands < 2)
        print_invalid_number(path);
    for (int i = 0; buf[i] != '\0'; i++)
        if (buf[i] == ',' || buf[i] == '\n' || mx_isdigit(buf[i]))
            buf[i] = '-';
    path->words = mx_count_words(buf, '-');
    path->uniq_isl = (char **)malloc(sizeof(char *) * path->words);
    path->islands = mx_strsplit(buf, '-');
    mx_strdel(&buf);
    unique_islands(path);
    double_islands(path);
    duplicate_bridges(path);
}

static void unique_islands(t_finder *path) {
    int num = 1;

    if (path->islands[0] == NULL)
        print_invalid_number(path);
    path->uniq_isl[0] = mx_strdup(path->islands[0]);
    for (int i = 1; i < path->words; i++) {
        for (int j = 0; j < num; ) {
            if (!mx_strcmp(path->uniq_isl[j], path->islands[i]))
                break;
            if (++j == num)
                path->uniq_isl[num++] = mx_strdup(path->islands[i]);
        }
    }
    if (path->num_islands != num) {
        mx_del_strarr(&path->uniq_isl);
        print_invalid_number(path);
    }
}

static void double_islands(t_finder *path) {
    int line = 2;

    for (int i = 1; i < path->words; i +=2) {
        if (!mx_strcmp(path->islands[i], path->islands[i - 1])) {
            mx_del_strarr(&path->islands);
            mx_del_strarr(&path->uniq_isl);
            mx_print_invalid_line(line, path);
        }
        line++;
    }
}

static void duplicate_bridges(t_finder *path) {
    for (int i = 0; i < path->words; i +=2) {
        for (int j = i + 2; j < path->words; j+=2) {
            if (!mx_strcmp(path->islands[i], path->islands[j])
                || !mx_strcmp(path->islands[i], path->islands[j + 1])) {
                if (!mx_strcmp(path->islands[i + 1], path->islands[j + 1])
                    || !mx_strcmp(path->islands[i + 1], path->islands[j])) {
                    mx_printerr("error: duplicate bridges\n");
                    mx_del_strarr(&path->islands);
                    exit(1);
                }
            }
        }
    }
}
