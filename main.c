#include "so_long.h"

int main()
{

	char **map;
	// t_point coords;
	// t_point map_size;

	// coords.x = 0;//player x pos
	// coords.y = 0;//player y pos
	// map_size.x = 50;//width
	// map_size.y = 70;//heigth
 	map = make_map("aaa.ber");
	//fill(map, map_size, coords, )
	int i = 0;

	ft_printf("%i\n", count_of(map, 'c'));

	while(map[i])
	{
		ft_printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}
	free(map);
	
}