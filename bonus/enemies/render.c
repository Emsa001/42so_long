/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:08:23 by escura            #+#    #+#             */
/*   Updated: 2024/01/25 18:14:06 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	render_enemies(t_data *data)
{
	const t_textures	*textures = data->textures;
	const t_scene		*scene = data->scene;
	int					i;
	int					j;

	i = 0;
	set_player_map(data);
	while (i < scene->player_map_rows)
	{
		j = 0;
		while (j < scene->player_map_cols)
		{
			if (scene->player_map[i][j] == 'X')
				load_image(textures->enemy[0], *data, j * scene->block_size, i
					* scene->block_size);
			j++;
		}
		i++;
	}
}
