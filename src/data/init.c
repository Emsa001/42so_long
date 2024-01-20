/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:49:38 by escura            #+#    #+#             */
/*   Updated: 2024/01/20 18:38:42 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_player(t_data *data)
{
    data->player = (t_player *)malloc(sizeof(t_player));
    t_player *player = data->player;
    
	player->moves = 0;
    player->texture = data->textures->player[0];
    set_real_position(data, &player->x, &player->y, 'P');
}

void init_map(t_data *data, char *map_string)
{
    data->scene = (t_scene *)malloc(sizeof(t_scene));

    t_scene *scene = data->scene;
    scene->block_size = 50;
    scene->rerender = NULL;
    scene->collectibles = count(map_string, 'C');

    convert_map(map_string, &scene->map, &scene->rows, &scene->cols);
    set_real_position(data, &scene->exit_x, &scene->exit_y, 'E');
}

void init_textures(t_data *data)
{
    data->textures = (t_textures *)malloc(sizeof(t_textures));
    t_textures *textures = data->textures;

    textures->wall = "./textures/wall.xpm";
    textures->floor = "./textures/floor.xpm";
    textures->exit = "./textures/chest.xpm";

    textures->player[0] = "./textures/player_right.xpm";
    textures->player[1] = "./textures/player_left.xpm";
    
    textures->collectible[0] = "./textures/potion_green.xpm";
    textures->collectible[1] = "./textures/potion_red.xpm";
    textures->collectible[2] = "./textures/potion_yellow.xpm";
}

void init_data(t_data *data, char *map_string)
{
    data->mlx = mlx_init();
    if (!data->mlx)
    {
        printf("Failed to initialize mlx\n");
        exit(1);
    }
    // textures init
    init_textures(data);

    // map init
    init_map(data, map_string);
    free(map_string);

    // player init
	init_player(data);

    // window init
    data->width = data->scene->cols * data->scene->block_size;
    data->height = data->scene->rows * data->scene->block_size;
    data->win = mlx_new_window(data->mlx, data->width, data->height, "So Long");
    
    if (!data->win)
    {
        printf("Failed to create window\n");
        exit(1);
    }
}
