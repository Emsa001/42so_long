/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:49:38 by escura            #+#    #+#             */
/*   Updated: 2024/01/21 23:11:21 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void init_enemies(t_data *data)
{
    const t_scene *scene = data->scene;
    
    int x = 0;
	int y = 0;
    int enemies = count(scene->map_string, 'X');
    data->enemy = (t_enemy **)malloc(sizeof(t_enemy) + enemies + 1);
    if(enemies == 0){
        data->enemy[0] = (t_enemy *)malloc(sizeof(t_enemy));
        data->enemy[0]->texture = 0;
        return;
    }
    int i = 0;
	while(x < scene->rows)
	{
        while(y < scene->cols)
        {
            if(scene->map[x][y] == 'X')
            {
                data->enemy[i] = (t_enemy *)malloc(sizeof(t_enemy));
                t_enemy *enemy = data->enemy[i++];
                
                enemy->texture = 0;
                enemy->direction = 0;
                enemy->alive = 1;
                enemy->x = x;
                enemy->y = y;
                enemy->prev_x = -1;
                enemy->prev_y = -1;
            }
            y++;
        }
        x++;
        y = 0;
	}
}

void	init_player(t_data *data)
{
    data->player = (t_player *)malloc(sizeof(t_player));
    t_player *player = data->player;
    
	player->moves = 0;
    player->alive = 1;
    player->attack = 0;
    player->direction = 0;
    player->texture = 0;
    set_real_position(data, &player->x, &player->y, 'P');
}

void init_map(t_data *data, char *map_string)
{
    data->scene = (t_scene *)malloc(sizeof(t_scene));
    t_scene *scene = data->scene;
    
    scene->block_size = 50;
    scene->rerender = NULL;
    scene->collectibles = count(map_string, 'C');
    scene->map_string = map_string;
    scene->boom_animation = 0;
    scene->exit_texture = 0;

    convert_map(map_string, &scene->map, &scene->rows, &scene->cols);
}

void init_textures(t_data *data)
{
    data->textures = (t_textures *)malloc(sizeof(t_textures));
    t_textures *textures = data->textures;

    textures->wall = "./new_textures/tiles/wall.xpm";
    textures->floor = "./new_textures/tiles/floor.xpm";
    textures->exit[0] = "./new_textures/tiles/doors_closed.xpm";
    textures->exit[1] = "./new_textures/tiles/doors_open.xpm";

    textures->enemy[0] = "./new_textures/enemy/right/idle_1.xpm";
    textures->enemy[1] = "./new_textures/enemy/right/idle_2.xpm";
    textures->enemy[2] = "./new_textures/enemy/right/idle_3.xpm";
    textures->enemy[3] = "./new_textures/enemy/right/idle_4.xpm";

    textures->player[0] = "./new_textures/player/right/idle_1.xpm";
    textures->player[1] = "./new_textures/player/right/idle_2.xpm";
    textures->player[2] = "./new_textures/player/right/idle_3.xpm";
    textures->player[3] = "./new_textures/player/right/idle_4.xpm";

    textures->player[4] = "./new_textures/player/left/idle_1.xpm";
    textures->player[5] = "./new_textures/player/left/idle_2.xpm";
    textures->player[6] = "./new_textures/player/left/idle_3.xpm";
    textures->player[7] = "./new_textures/player/left/idle_4.xpm";

    textures->player[8] = "./new_textures/player/dead/1.xpm";
    textures->player[9] = "./new_textures/player/dead/2.xpm";
    textures->player[10] = "./new_textures/player/dead/3.xpm";
    textures->player[11] = "./new_textures/player/dead/4.xpm";
    

    textures->collectible[0] = "./new_textures/items/potion.xpm";
    textures->collectible[1] = "./new_textures/items/sword.xpm";

    textures->explosion[0] = "./new_textures/explosion/1.xpm";
    textures->explosion[1] = "./new_textures/explosion/2.xpm";
    textures->explosion[2] = "./new_textures/explosion/3.xpm";
    textures->explosion[3] = "./new_textures/explosion/4.xpm";
    textures->explosion[4] = textures->floor;

    textures->message[0] = "./new_textures/ui/message.xpm";
    textures->message[1] = "./new_textures/ui/broadcast.xpm";
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
    // player init
	init_player(data);
    init_enemies(data);

    // window init
    data->frame_update = 0;
    data->width = data->scene->cols * data->scene->block_size;
    data->height = data->scene->rows * data->scene->block_size;
    data->win = mlx_new_window(data->mlx, data->width, data->height, "So Long");
    data->game_over = 0;
    
    if (!data->win)
    {
        printf("Failed to create window\n");
        exit(1);
    }
}
