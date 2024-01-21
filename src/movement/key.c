/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:50:17 by escura            #+#    #+#             */
/*   Updated: 2024/01/21 23:41:11 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		free_data(data);

    const t_textures *textures = data->textures;
    t_player *player = data->player;
    t_scene *scene = data->scene;

    if(player->alive == 0)
        return -1;

    int x = player->x;
    int y = player->y;

	// d
	if(keycode == 2){
        player->direction = 0;
        y++;
	}	

	// a
	if(keycode == 0){
        player->direction = 1;
        y--;
	}

    // w
    if(keycode == 13){
        x--;
    }

    // s
    if(keycode == 1){
        x++;
    }

    // space
    if(keycode == 49){
        if(player->attack == 1){
            if(player->direction == 0)
                kill_enemy(data,x,y + 1);
            else
                kill_enemy(data,x,y - 1);
        }
        else
            show_text(data, "I need a sword to kill the goblin!\n");
    }

    // b
    if(keycode == 11){
        boom(data);
        return -1;
    }

    int temp_x = player->x;
    int temp_y = player->y;

    if((x != temp_x || y != temp_y) && check_if_safe(data, x, y) && data->game_over == 0){
        if(scene->rerender != NULL)
            re_render(data);

        if(check_objectives(data,x,y) != 1)
            return (-1);
        if(player->alive == 1){
            scene->map[player->x][player->y] = '-';
            player->x = x;
            player->y = y;
            scene->map[x][y] = 'P';
        }
        player->moves++;
        render_dynamic(*data);
    }
        
	return (-1);
}