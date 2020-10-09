#include "pathfinder.h"

static bool check_line(int i, int *line, char *str, t_pfinder *path) {
    char *temp1 = NULL;
    char *temp2 = NULL;
    int count = 0;

    for (int j = i + 1; str[j] != '\0'; j++) {
        temp1 = &str[j];
        for (;mx_isalpha(str[j]); j++);
        if (str[j++] != '-')
            return mx_print_error_line(*line, path);
        temp2 = &str[j];
        for (count = 0 ;mx_isalpha(str[j]); j++, count++);
        if (str[j++] != ',')
            return mx_print_error_line(*line, path);
        if ((i = mx_strncmp(temp1, temp2, count)) == 0)
            return mx_print_error_line(*line, path);
        for (;mx_isdigit(str[j]); j++);
        if (str[j] != '\n') 
            return mx_print_error_line(*line, path);
        (*line)++;
    }
    return false;
}

bool mx_check_line(char *str, t_pfinder *path) {
    int i;
    int line = 1;
    int count = 0;
    
    for (i = 0; mx_isdigit(str[i]); i++) {
        count *= 10;
        count += str[i] - 48;
    }
    if ((path->count = count) == 0)
        exit(0);
    if (str[i] != '\n' || str[i] == '\0')
        return mx_print_error_line(line, path);
    line++;
    if (check_line(i, &line, str, path))
        return true;
    path->line = line;
    return false;
}
