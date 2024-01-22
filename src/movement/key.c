/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:50:17 by escura            #+#    #+#             */
/*   Updated: 2024/01/22 19:17:23 by escura           ###   ########.fr       */
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
    
    if(data->game_over == 1)
        return -1;

    int x = player->x;
    int y = player->y;

	if(keycode == 2){
        player->direction = 0;
        y++;
	}	

	if(keycode == 0){
        player->direction = 1;
        y--;
	}

    if(keycode == 13)
        x--;

    if(keycode == 1)
        x++;

    if((x != player->x || y != player->y) && check_if_safe(data, x, y) && data->game_over == 0){
        if(check_objectives(data,x,y) != 1)
            return (-1);

        scene->map[player->x][player->y] = '0';
        player->x = x;
        player->y = y;
        scene->map[x][y] = 'P';
        player->moves++;

        render_player_view(*data,0);
    }
        
	return (-1);
}
