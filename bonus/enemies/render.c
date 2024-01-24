/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:08:23 by escura            #+#    #+#             */
/*   Updated: 2024/01/24 20:48:01 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	render_enemies(t_data *data)
{
	t_textures *textures = data->textures;
	t_scene *scene = data->scene;
	int i;
	int j;

	i = 0;
	while (i < scene->rows )
	{
		j = 0;
		while (j < scene->cols )
		{
			if (scene->map[i][j] == 'X')
				load_image(textures->enemy[0], *data, j * scene->block_size, i * scene->block_size);
			j++;
		}
		i++;
	}
}

void render_enemy(t_data *data, t_player *enemy)
{
    const t_textures *textures = data->textures;
    t_scene *scene = data->scene;

    if(enemy->alive == 0)
        return;
    
    
	load_image(textures->floor, *data, enemy->prev_y * scene->block_size, enemy->prev_x * scene->block_size);
    load_image(textures->floor, *data, enemy->y * scene->block_size, enemy->x * scene->block_size);
    load_image(textures->enemy[enemy->texture], *data, enemy->y * scene->block_size, enemy->x * scene->block_size);
}