/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:49:38 by escura            #+#    #+#             */
/*   Updated: 2024/01/24 14:16:49 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus_old.h"

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
    player->bombs = 3;
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

    textures->wall = "./textures/tiles/wall.xpm";
    textures->floor = "./textures/tiles/floor.xpm";
    textures->exit[0] = "./textures/tiles/doors_closed.xpm";
    textures->exit[1] = "./textures/tiles/doors_open.xpm";

    textures->enemy[0] = "./textures/enemy/right/idle_1.xpm";
    textures->enemy[1] = "./textures/enemy/right/idle_2.xpm";
    textures->enemy[2] = "./textures/enemy/right/idle_3.xpm";
    textures->enemy[3] = "./textures/enemy/right/idle_4.xpm";

    textures->enemy[4] = "./textures/enemy/dead/1.xpm";
    textures->enemy[5] = "./textures/enemy/dead/2.xpm";
    textures->enemy[6] = "./textures/enemy/dead/3.xpm";
    textures->enemy[7] = "./textures/enemy/dead/4.xpm";

    textures->player[0] = "./textures/player/right/idle_1.xpm";
    textures->player[1] = "./textures/player/right/idle_2.xpm";
    textures->player[2] = "./textures/player/right/idle_3.xpm";
    textures->player[3] = "./textures/player/right/idle_4.xpm";

    textures->player[4] = "./textures/player/left/idle_1.xpm";
    textures->player[5] = "./textures/player/left/idle_2.xpm";
    textures->player[6] = "./textures/player/left/idle_3.xpm";
    textures->player[7] = "./textures/player/left/idle_4.xpm";

    textures->player[8] = "./textures/player/dead/1.xpm";
    textures->player[9] = "./textures/player/dead/2.xpm";
    textures->player[10] = "./textures/player/dead/3.xpm";
    textures->player[11] = "./textures/player/dead/4.xpm";
    

    textures->collectible[0] = "./textures/items/potion.xpm";
    textures->collectible[1] = "./textures/items/sword.xpm";

    textures->explosion[0] = "./textures/explosion/1.xpm";
    textures->explosion[1] = "./textures/explosion/2.xpm";
    textures->explosion[2] = "./textures/explosion/3.xpm";
    textures->explosion[3] = "./textures/explosion/4.xpm";
    textures->explosion[4] = textures->floor;

    textures->message[0] = "./textures/ui/message.xpm";
    textures->message[1] = "./textures/ui/broadcast.xpm";
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
