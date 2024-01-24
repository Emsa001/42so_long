/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:15:02 by escura            #+#    #+#             */
/*   Updated: 2024/01/24 20:44:48 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	render_moves(t_data data)
{
	const t_scene	*scene = data.scene;
	const t_player	*player = data.player;
	char			*moves;
	char			*collectibles;

	moves = ft_itoa(player->moves);
	load_image(data.textures->message[0], data, 1, 1);
	mlx_string_put(data.mlx, data.win, 20, 15, 0x00f59e0b, "MOVES:");
	mlx_string_put(data.mlx, data.win, 80, 15, 0x00f59e0b, moves);
	free(moves);
	if (data.width >= 250)
	{
		collectibles = ft_itoa(scene->collectibles);
		load_image(data.textures->message[0], data, data.width - 151, 1);
		mlx_string_put(data.mlx, data.win, data.width - 130, 15, 0x00f59e0b,
			"POTIONS:");
		mlx_string_put(data.mlx, data.win, data.width - 50, 15, 0x00f59e0b,
			collectibles);
		free(collectibles);
	}
}

void	boom_animation(t_data *data)
{
	t_scene	*scene;

	scene = data->scene;
	if (data->frame_update % 500 == 0)
	{
		if (scene->boom_animation < 4)
			scene->boom_animation++;
	}
	render_player_view(*data, 0);
}

void	animation_update(t_data data)
{
	const t_textures	*textures = data.textures;
	t_player			*player;
	int					x;
	int					y;

	player = data.player;
	if (player->texture >= 3 && player->alive == 1)
		player->texture = 0;
	else
		player->texture++;
	if (data.scene->boom_animation != -1 && data.scene->boom_animation < 4)
		boom_animation(&data);
	set_pixel_position(&data, &x, &y, 'P');
	load_image(textures->floor, data, x, y);
	load_image(textures->player[player->texture + player->texture_add], data, x,
		y);
	explode_bombs(&data);
}
