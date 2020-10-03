
#include <stdio.h>
#include <fcntl.h>

#include "libmx.h"


typedef struct s_pfinder
{
    char *file;
}              t_pfinder;

void mx_check_error(int argc, char *argv[], t_pfinder *path);
int mx_check_exist(int argc, char *argv[]);
char *mx_check_empty(int fd, char *argv);
int mx_check_line(char *str);




