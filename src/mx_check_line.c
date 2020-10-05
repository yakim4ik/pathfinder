#include "pathfinder.h"

// static void free_temp(char *temp1, char *temp2) {
//     free(temp1);
//     free(temp2);
// }

bool mx_check_line(char *str, t_pfinder *path) {
    int i;
    int line = 1;
    // char *temp1 = NULL;
    // char *temp2 = NULL;
    // char c;
    
    for (i = 0; mx_isdigit(str[i]); i++) {
        path->count *= 10;
        path->count += str[i] - 48;
    }
    if (str[i] != '\n' || str[i] == '\0')
        return mx_print_error_line(line, path);
    line++;
    for (int j = i + 1; str[j] != '\0'; j++) {
        // temp1 = NULL;
        // temp2 = NULL;
        for (;mx_isalpha(str[j]); j++) {
            // c = str[j];
            // temp1 = mx_strjoin(temp1, &c);
        }
        // mx_printstr(temp1);
        // mx_printstr("\n");
        if (str[j++] != '-') {
            return mx_print_error_line(line, path);
        }
        for (;mx_isalpha(str[j]); j++) {
            //  c = str[j];
            // temp2 = mx_strjoin(temp2, &c);
        }
        // mx_printstr(temp2);
        // mx_printstr("\n");
        if (str[j++] != ',') {
            // free_temp(temp1, temp2);
            return mx_print_error_line(line, path);
        }
        // if ((i = mx_strcmp(temp1, temp2)) == 0) {
        //     free_temp(temp1, temp2);
        //     return mx_print_error_line(line, path);
        // }
        for (;mx_isdigit(str[j]); j++);
        if (str[j] != '\n') {
            // free_temp(temp1, temp2);
            return mx_print_error_line(line, path);
        }
        // free_temp(temp1, temp2);
        // system("leaks -q pathfinder");
        line++;
    }
    mx_printstr("@@@@@@\n");
    // system("leaks -q pathfinder");
    // free_temp(temp1, temp2);
    return false;
}
