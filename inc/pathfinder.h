
#include <stdio.h>
#include <fcntl.h>

#include "libmx.h"


typedef struct s_pfinder
{
    // char **lines;
    long count;
    int line;
    char **islnads;
}              t_pfinder;

void mx_check_error(int argc, char *argv[], t_pfinder *path);
int mx_check_exist(int argc, char *argv[]);
char *mx_check_empty(int fd, char *argv);
bool mx_check_line(char *str, t_pfinder *path);
bool mx_split_file (char *str, t_pfinder *path);
bool mx_print_error_line (int line, t_pfinder *path);

t_pfinder *init_pathfinder(t_pfinder *path);
void free_pathfinder(t_pfinder *path);
