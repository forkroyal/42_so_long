#include "so_long.h"

// int check_path(struct s_mapdata mapdata);
int fill_mapdata(struct s_mapdata *data, char *mapfile);

// int check_path(struct s_mapdata mapdata)
// {
//     // char **map_copy;
//     return 1;




// }

int fill_mapdata(struct s_mapdata *data, char *mapfile)
{
    data->map_height = count_lines(mapfile);
    return 1;

}