#include "pathfinder.h"

t_pfinder *init_pathfinder(t_pfinder *path) {
    path = (t_pfinder *)malloc(sizeof(t_pfinder));
    path->count = 0;
    path->line = 0;
    return path;
    
    // path->count = malloc(sizeof(int));
}
