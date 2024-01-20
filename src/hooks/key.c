/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:50:17 by escura            #+#    #+#             */
/*   Updated: 2024/01/20 18:32:30 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int check_if_safe(t_data *data, int x, int y)
{
    t_scene *scene = data->scene;
    t_player *player = data->player;

    if(scene->map[x][y] == '1')
        return (0);

    return (1);
}

int check_objectives(t_data *data, int x, int y)
{
    t_scene *scene = data->scene;
    t_player *player = data->player;

    if(scene->map[x][y] == 'C')
    {
        show_text(data, "Great Job!\n");
        scene->collectibles--;
    }

    if(scene->map[x][y] == 'E')
    {
        if(scene->collectibles == 0)
            victory(data);
        else{
            show_text(data,"I cannot leave any potions");
            return 0;
        }
    }

    return 1;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		free_data(data);
    
    const t_textures *textures = data->textures;
    t_player *player = data->player;
    t_scene *scene = data->scene;

    int x = player->x;
    int y = player->y;

	// d
	if(keycode == 2){
		player->texture = textures->player[0];
        y++;
	}	

	// a
	if(keycode == 0){
		player->texture = textures->player[1];
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

    int temp_x = player->x;
    int temp_y = player->y;

    if(check_if_safe(data, x, y)){
        if(scene->rerender != NULL)
            re_render(data);
        
        if(check_objectives(data,x,y) == 0)
            return (-1);
    
		scene->map[player->x][player->y] = '-';
        player->x = x;
        player->y = y;
        scene->map[x][y] = 'P';
        player->moves++;
        render_dynamic(*data);
        scene->map[temp_x][temp_y] = '0';

    }
        
	return (-1);
}