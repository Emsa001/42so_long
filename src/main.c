#include "../includes/so_long.h"
#include <stdio.h>


int map_get_rows(char *map)
{
	int rows = 0;
	int i = 0;
	while(map[i] != '\0')
	{
		if(map[i] == ',')
			rows++;
		i++;
	}
	return rows;
}

int map_get_cols(char *map)
{
	int cols = 0;
	int i = 0;
	while(map[i] != '\0')
	{
		if(map[i] == ',')
			break;
		cols++;
		i++;
	}
	return cols;
}

int	main(void)
{
	t_data data;

	char *map = "1111111111111,10010000000C1,1000011111001,1P0011E000001,1111111111111";
	init_data(&data, map);

	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);

	render_scene(data);

	mlx_do_sync(data.mlx);
	mlx_loop(data.mlx);
	return (0);
}