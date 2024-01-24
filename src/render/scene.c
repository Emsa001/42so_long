/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:26:31 by escura            #+#    #+#             */
/*   Updated: 2024/01/24 14:40:05 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	set_player_texture(t_data data)
{
	const t_player	*player = data.player;
	int				player_texture;

	player_texture = player->texture + player->texture_add;
	if (player->running && player->direction == 0)
		player_texture = 4;
	else if (player->running && player->direction == 1)
		player_texture = 9;
	return (player_texture);
}

static void	render_images(t_data data, int i, int j)
{
	const t_scene	*scene = data.scene;
	const char		block = scene->player_map[i][j];

	if (block == ' ')
		load_image(data.textures->empty, data, j * scene->block_size, i
			* scene->block_size);
	if (block == '1')
		load_image(data.textures->wall, data, j * scene->block_size, i
			* scene->block_size);
	else if (block != ' ')
		load_image(data.textures->floor, data, j * scene->block_size, i
			* scene->block_size);
	if (block == 'C')
		load_image(data.textures->collectible, data, j * scene->block_size, i
			* scene->block_size);
	else if (block == 'E')
		load_image(data.textures->exit[scene->exit_texture], data, j
			* scene->block_size, i * scene->block_size);
	else if (block == 'P')
		load_image(data.textures->player[set_player_texture(data)], data, j
			* scene->block_size, i * scene->block_size);
}

void	render_player_view(t_data data, int i)
{
	const t_scene	*scene = data.scene;
	const int		temp_i = i;
	int				j;

	set_player_map(&data);
	while (i < scene->player_map_rows)
	{
		j = 0;
		while (j < scene->player_map_cols)
			render_images(data, i, j++);
		i++;
	}
	if (temp_i == 0)
		render_moves(data);
}
