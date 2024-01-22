/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 18:02:35 by escura            #+#    #+#             */
/*   Updated: 2024/01/22 14:54:19 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void boom(t_data *data)
{
    t_player *player = data->player;
    t_scene *scene = data->scene;
    if(player->bombs == 0)
        return;
    player->bombs--;
    scene->boom_animation = 0;

    int x = player->x;
    int y = player->y;
    int radius = 1;

    for (int i = x - radius; i <= x + radius; i++) {
        for (int j = y - radius; j <= y + radius; j++) {
            int temp_x = i;
            int temp_y = j;

            if(temp_x < 1)
                temp_x = 1;
            if(temp_y < 1)
                temp_y = 1;
            
            if(temp_x >= scene->rows - 1)
                temp_x = scene->rows - 2;
            if(temp_y >= scene->cols - 1)
                temp_y = scene->cols - 2;
            
            if(scene->map[temp_x][temp_y] == '1' || scene->map[temp_x][temp_y] == 'X'){
                if(scene->map[temp_x][temp_y] == 'X')
                    kill_enemy(data, temp_x, temp_y);
                scene->map[temp_x][temp_y] = 'B';
            }
        }
    }
    render_dynamic(*data);
}
