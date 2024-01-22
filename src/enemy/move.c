/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:25:17 by escura            #+#    #+#             */
/*   Updated: 2024/01/22 13:46:48 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void go_up(t_data *data, t_enemy *enemy){
    t_scene *scene = data->scene;

    char next_position = scene->map[enemy->x - 1][enemy->y];
    
    if(next_position == 'P')
    {
        kill_player(data);
        return ;
    }

    if(next_position == '1' || next_position == 'E' || next_position == 'C')
    {
        enemy->direction = 1;
        return ;
    }

    scene->map[enemy->x][enemy->y] = '0';
    enemy->x--;
    scene->map[enemy->x][enemy->y] = 'X';
}

void go_down(t_data *data, t_enemy *enemy){
    t_scene *scene = data->scene;
    
    char next_position = scene->map[enemy->x + 1][enemy->y];

    if(next_position == 'P')
    {
        kill_player(data);
        return ;
    }

    if(next_position == '1' || next_position == 'E' || next_position == 'C')
    {
        enemy->direction = 0;
        return ;
    }

    scene->map[enemy->x][enemy->y] = '0';
    enemy->x++;
    scene->map[enemy->x][enemy->y] = 'X';

}

int enemy_move(t_data *data, t_enemy *enemy)
{
    const t_textures *textures = data->textures;
    t_scene *scene = data->scene;

    int x = enemy->x;
    int y = enemy->y;

    enemy->prev_x = x;
    enemy->prev_y = y;

    if(enemy->alive == 0)
        return 0;


    if(enemy->direction == 0)
        go_up(data, enemy);
    else
        go_down(data, enemy);

    if(x == enemy->x)
        return -1;

    render_enemy(data, enemy);
    return -1;
}

void render_enemy(t_data *data, t_enemy *enemy)
{
    const t_textures *textures = data->textures;
    t_scene *scene = data->scene;

    if(enemy->alive == 0){
        if(enemy->texture > 4){
            scene->map[enemy->x][enemy->y] = '0';
            return;
        }

        load_image(textures->floor, *data, enemy->y * scene->block_size, enemy->x * scene->block_size);
        load_image(textures->enemy[enemy->texture + 3], *data, enemy->y * scene->block_size, enemy->x * scene->block_size);
        return;
    }
    
    load_image(textures->floor, *data, enemy->prev_y * scene->block_size, enemy->prev_x * scene->block_size);
    load_image(textures->floor, *data, enemy->y * scene->block_size, enemy->x * scene->block_size);
    load_image(textures->enemy[enemy->texture], *data, enemy->y * scene->block_size, enemy->x * scene->block_size);
}