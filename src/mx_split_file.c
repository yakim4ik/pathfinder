#include "pathfinder.h"

bool mx_split_file (char *str, t_pfinder *path) {
    char **lines = NULL;
    int j = 0;

    if (path->line <= 2) {
        mx_printerror("error: invalid number of islands\n");
        return true;
    } 
    for (int i = 0; str[i]; i++)
        if(str[i] == '-' || str[i] == ',')
            str[i] = '\n';
    lines = mx_strsplit(str, '\n');
    path->islands = (char **)malloc(sizeof(char *) * ((path->line - 2) * 2 + 1));
    path->islands[(path->line - 2) * 2 + 1] = NULL;
    path->islands[0] = mx_strdup(lines[1]);
    for (int i = 1; lines[i]; i += 3) {
        for(j = 0; path->islands[j] && mx_strcmp(lines[i], path->islands[j]) != 0; j++);
        if (path->islands[j] == NULL)
            path->islands[j] = mx_strdup(lines[i]);
        for(j = 0; path->islands[j] && mx_strcmp(lines[i+1], path->islands[j]) != 0; j++);
        if (path->islands[j] == NULL)
            path->islands[j] = mx_strdup(lines[i+1]);
    }
    for (j = 0; path->islands[j]; j++);

    if (path->count != (long)j) {
        mx_printerror("error: invalid number of islands\n");
        mx_del_strarr(&lines);

        return true;
    }
    mx_del_strarr(&lines);
    system("leaks -q pathfinder");
    return false;
}
