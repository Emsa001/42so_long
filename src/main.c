#include "../includes/so_long.h"


int	main(int nb, char **args)
{
	t_data data;
	char *map;
	if(args[1] == NULL)
		map = read_map("map.ber");
	else
		map = read_map(args[1]);

	init_data(&data, map);
	if(!is_possible(map))
	{
		printf("Invalid map\n");
		exit(1);
	}
	free(map);
	mlx_key_hook(data.win, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);

	render_static(data);
	render_scene(&data);

	// mlx_do_sync(data.mlx);
	mlx_loop(data.mlx);
	return (0);
}