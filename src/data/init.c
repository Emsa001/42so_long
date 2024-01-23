/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:49:38 by escura            #+#    #+#             */
/*   Updated: 2024/01/23 00:38:13 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_player(t_data *data)
{
	t_player	*player;

	data->player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (data->player == NULL)
	{
		ft_printf("Error: Failed to allocate memory for player\n");
		exit(1);
	}
	player = data->player;
	player->moves = 0;
	player->direction = 0;
	player->texture = 0;
	set_real_position(data, &player->x, &player->y, 'P');
	set_player_map(data);
}

void	init_map(t_data *data, char *map_string)
{
	t_scene	*scene;

	data->scene = (t_scene *)ft_calloc(1, sizeof(t_scene));
	if (data->scene == NULL)
	{
		ft_printf("Error: Failed to allocate memory for player\n");
		exit(1);
	}
	scene = data->scene;
	scene->block_size = 50;
	scene->collectibles = count(map_string, 'C');
	scene->map_string = map_string;
	scene->exit_texture = 0;
	scene->text = NULL;
	scene->player_map = NULL;
	convert_map(map_string, &scene->map, &scene->rows, &scene->cols);
	scene->player_map_rows = 20;
	scene->player_map_cols = 20;
	if (scene->rows < 20)
		scene->player_map_rows = scene->rows;
	if (scene->cols < 20)
		scene->player_map_cols = scene->cols;
}

void	init_textures(t_data *data)
{
	t_textures	*textures;

	data->textures = (t_textures *)ft_calloc(1, sizeof(t_textures));
	if (data->textures == NULL)
	{
		ft_printf("Failed to allocate memory for textures\n");
		exit(1);
	}
	textures = data->textures;
	textures->empty = "./textures/tiles/empty.xpm";
	textures->wall = "./textures/tiles/wall.xpm";
	textures->floor = "./textures/tiles/floor.xpm";
	textures->exit[0] = "./textures/tiles/doors_closed.xpm";
	textures->exit[1] = "./textures/tiles/doors_open.xpm";
	textures->player[0] = "./textures/player/right/idle_1.xpm";
	textures->player[1] = "./textures/player/right/idle_2.xpm";
	textures->player[2] = "./textures/player/right/idle_3.xpm";
	textures->player[3] = "./textures/player/right/idle_4.xpm";
	textures->player[4] = "./textures/player/left/idle_1.xpm";
	textures->player[5] = "./textures/player/left/idle_2.xpm";
	textures->player[6] = "./textures/player/left/idle_3.xpm";
	textures->player[7] = "./textures/player/left/idle_4.xpm";
	textures->collectible = "./textures/items/potion.xpm";
	textures->message[0] = "./textures/ui/message.xpm";
	textures->message[1] = "./textures/ui/broadcast.xpm";
}

void	init_data(t_data *data, char *map_string)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_printf("Error: Failed to initialize mlx\n");
		exit(1);
	}
	init_textures(data);
	init_map(data, map_string);
	init_player(data);
	data->game_over = 0;
	data->frame_update = 0;
	data->width = data->scene->cols * data->scene->block_size;
	data->height = data->scene->rows * data->scene->block_size;
	if (data->width > 1000)
		data->width = 1000;
	if (data->height > 1000)
		data->height = 1000;
	data->win = mlx_new_window(data->mlx, data->width, data->height, "So Long");
	if (!data->win)
		free_data(data);
}
