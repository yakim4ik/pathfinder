#include "pathfinder.h"

bool mx_split_file (char *str, t_pfinder *path) {
    char **lines = NULL;
    int count = 0;
    int size = 0;

    for (int i = 0; str[i]; i++) {
        str[i] == '\n' ? count++ : str[i];
        if(str[i] == '-' || str[i] == ',')
            str[i] = '\n';
    }
    lines = mx_strsplit(str, '\n');
    if (count < 2) {
        mx_printerror("error: invalid number of islands\n");
        mx_del_strarr(&lines);
        return true;
    }
    path->count = count;
    for (int i = 0; lines[i]; i++) {
        mx_printstr(lines[i]);
        mx_printchar('\n');
    }
    for (int i = 1; i < count; i += 3) {
        size = 0;
        while(lines[i][size] == lines[i][size])
            size++;
        if(lines[i - 1][size] == lines[i][size]) {
            mx_print_error_line((i/3 + 1), path);
            mx_del_strarr(&lines);
            return true;
        }

    }
    mx_del_strarr(&lines);
    return false;
    // path->islnads = (char **)malloc(sizeof(char *) * (path->count + 1));
    // mx_printstr("\n\n");
    // mx_printint(path->count);
    // mx_del_strarr(&lines);
}
