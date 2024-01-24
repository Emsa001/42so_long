/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:15:02 by escura            #+#    #+#             */
/*   Updated: 2024/01/24 13:54:30 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
	ft_printf("Moves: %s\n", moves);
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

void	animation_update(t_data data)
{
	const t_textures	*textures = data.textures;
	const t_player		*player = data.player;
	int					x;
	int					y;

	set_pixel_position(&data, &x, &y, 'P');
	load_image(textures->floor, data, x, y);
	load_image(textures->player[player->texture + player->texture_add], data, x,
		y);
}
