#include "pathfinder.h"

int mx_check_line(char *str) {
    int i = 0;
    char **lines = NULL;

    
    lines = mx_strsplit(str, '\n');

    for (i = 0; lines[i] != NULL; i++) {
        mx_printstr(lines[i]);
        mx_printstr("\n");
    }

    mx_del_strarr(&lines);
    return 0;
}
