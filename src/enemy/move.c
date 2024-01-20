/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:25:17 by escura            #+#    #+#             */
/*   Updated: 2024/01/20 21:52:30 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void go_up(t_enemy *enemy, t_scene *scene){
    scene->map[enemy->x][enemy->y] = '-';
    enemy->x--;
    scene->map[enemy->x][enemy->y] = 'X';
}

void go_down(t_enemy *enemy, t_scene *scene){
    scene->map[enemy->x][enemy->y] = '-';
    enemy->x++;
    scene->map[enemy->x][enemy->y] = 'X';
}

int enemy_move(t_data *data)
{
    t_enemy *enemy = data->enemy;
    t_scene *scene = data->scene;
    int x = enemy->x;
    int y = enemy->y;

    enemy->prev_x = x;
    enemy->prev_y = y;

    if(enemy->alive == 0)
        return 0;

    if(enemy->direction == 0){
        if(scene->map[x + 1][y] == 'P')
            kill_player(data);
        
        if(scene->map[x + 1][y] != '0'){
            enemy->direction = 1;
            go_up(enemy, scene);
        }
        else    
            go_down(enemy, scene);
    }
    else{
        if(scene->map[x - 1][y] == 'P')
            kill_player(data);
        else if(scene->map[x - 1][y] != '0'){
            enemy->direction = 0;
            go_down(enemy, scene);
        }
        else
            go_up(enemy, scene);
    }

    return -1;
}