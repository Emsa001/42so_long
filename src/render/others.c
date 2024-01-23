/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:15:02 by escura            #+#    #+#             */
/*   Updated: 2024/01/23 18:13:50 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_moves(t_data data)
{
	t_scene			*scene;
	const t_player	*player = data.player;
	char			*moves;

	scene = data.scene;
	moves = ft_itoa(player->moves);
	mlx_string_put(data.mlx, data.win, 5, 5, 0x00f59e0b, "Moves:");
	mlx_string_put(data.mlx, data.win, 70, 5, 0x00f59e0b, moves);
	ft_printf("Moves: %s\n", moves);
	free(moves);
}

void	animation_update(t_data data)
{
	const t_textures	*textures = data.textures;
	const t_player		*player = data.player;
	int					x;
	int					y;

	set_pixel_position(&data, &x, &y, 'P');
	load_image(textures->floor, data, x, y);
	load_image(textures->player[player->texture + player->texture_add], data,
		x, y);
}
