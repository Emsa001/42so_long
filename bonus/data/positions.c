/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:44:40 by escura            #+#    #+#             */
/*   Updated: 2024/01/24 14:14:47 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	set_pixel_position(t_data *data, int *x, int *y, char c)
{
	const t_scene	*scene = data->scene;
	int				i;
	int				j;

	i = 0;
	while (i < scene->player_map_rows)
	{
		j = 0;
		while (j < scene->player_map_cols)
		{
			if (scene->player_map[i][j] == c)
			{
				*x = j * scene->block_size;
				*y = i * scene->block_size;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	set_real_position(t_data *data, int *x_pos, int *y_pos, char c)
{
	const t_scene	*scene = data->scene;
	int				x;
	int				y;

	x = 0;
	y = 0;
	while (scene->map[x][y] != c)
	{
		y++;
		if (y == scene->cols)
		{
			y = 0;
			x++;
		}
	}
	*x_pos = x;
	*y_pos = y;
}
