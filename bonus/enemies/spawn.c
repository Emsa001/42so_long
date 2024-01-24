/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:19:53 by escura            #+#    #+#             */
/*   Updated: 2024/01/24 20:48:40 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void init_enemies(t_data *data)
{
    const t_scene *scene = data->scene;
    
    int	x;
    int	y;
    int i = 0;

    int enemies = data->scene->enemies_alive;
    data->enemy = (t_player **)ft_calloc(enemies, sizeof(t_player *));
    if(enemies == 0){
        data->enemy[0] = (t_player *)ft_calloc(0, sizeof(t_player) + 1);
        data->enemy[0]->texture = 0;
        return;
    }
    x = 1;
	while(x < scene->rows - 1)
	{
        y = 1;
        while(y < scene->cols - 1)
        {
            if(scene->map[x][y] == 'X')
            {
                data->enemy[i] = (t_player *)ft_calloc(1, sizeof(t_player));
                data->enemy[i]->texture = 0;
                data->enemy[i]->direction = 0;
                data->enemy[i]->alive = 1;
                data->enemy[i]->x = x;
                data->enemy[i]->y = y;
                data->enemy[i]->prev_x = 0;
                data->enemy[i]->prev_y = 0;
                i++;
            }
            y++;
        }
        x++;
	}
}

static int can_be_placed(t_data *data, int i, int j) 
{
    const t_scene *scene = data->scene;
    if(rnd(1,5) != 1)
        return 0;

    if (scene->map[i][j] != '0' || (scene->map[i - 1][j] != '0' && scene->map[i + 1][j] != '0')) {
        return 0;
    }

    for (int i = 0; i < scene->rows; i++) {
        if (data->scene->map[i][j] == 'X' || scene->map[i][j] == 'P') {
            return 0;
        }
    }
    
    return 1;
}

void spawn_enemies(t_data *data)
{
    const t_textures *textures = data->textures;
    const t_scene *scene = data->scene;
    int	i;
    int	j;

    if(scene->rows <= 3){
        ft_printf("No enough space for enemies\n");
        return;
    }

    i = 1;
    while (i < scene->rows - 1)
    {
        j = 1;
        while (j < scene->cols - 1)
        {            
            if (can_be_placed(data, i, j)){
                data->scene->map[i][j] = 'X';
                data->scene->enemies_alive++;
                ft_printf("Spawned enemy %d at %d, %d\n",data->scene->enemies_alive, i, j);
            }
            j++;
        }
        i++;

        if(data->scene->enemies_alive == 0 && i == scene->rows - 1)
            i = 1;
    }
    
    init_enemies(data);
    render_enemies(data);
}