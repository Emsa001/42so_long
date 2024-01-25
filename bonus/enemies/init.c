/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:15:06 by escura            #+#    #+#             */
/*   Updated: 2024/01/25 18:27:21 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	init_enemies_2(t_data *data)
{
	int	x;
	int	i;
	int	y;

	x = 1;
	i = 0;
	y = 0;
	while (x < data->scene->rows - 1)
	{
		y = 1;
		while (y < data->scene->cols - 1)
		{
			if (data->scene->map[x][y] == 'X')
			{
				data->enemy[i] = (t_player *)ft_calloc(1, sizeof(t_player));
				data->enemy[i]->texture = 0;
				data->enemy[i]->alive = 1;
				data->enemy[i]->x = x;
				data->enemy[i]->y = y;
				i++;
			}
			y++;
		}
		x++;
	}
}

void	init_enemies(t_data *data)
{
	const int	enemies = data->scene->enemies_alive;

	data->enemy = (t_player **)ft_calloc(enemies, sizeof(t_player *));
	if (enemies == 0)
	{
		data->enemy[0] = (t_player *)ft_calloc(0, sizeof(t_player) + 1);
		data->enemy[0]->texture = 0;
		return ;
	}
	init_enemies_2(data);
}
