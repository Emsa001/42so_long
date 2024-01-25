/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:19:53 by escura            #+#    #+#             */
/*   Updated: 2024/01/25 18:17:22 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static int	can_be_placed(t_data *data, int i, int j)
{
	const t_scene	*scene = data->scene;
	int				k;

	k = 0;
	if (rnd(1, 5) != 1)
		return (0);
	if (scene->map[i][j] != '0' || (scene->map[i - 1][j] != '0' && scene->map[i
			+ 1][j] != '0'))
		return (0);
	while (k < scene->rows)
	{
		if (data->scene->map[k][j] == 'X' || scene->map[k][j] == 'P')
			return (0);
		k++;
	}
	return (1);
}

static void	spawn_enemies_2(t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < data->scene->rows - 1)
	{
		j = 1;
		while (j < data->scene->cols - 1)
		{
			if (can_be_placed(data, i, j))
			{
				data->scene->map[i][j] = 'X';
				data->scene->enemies_alive++;
			}
			j++;
		}
		i++;
		if (data->scene->enemies_alive == 0 && i == data->scene->rows - 1)
			i = 1;
	}
}

void	spawn_enemies(t_data *data)
{
	if (data->scene->rows <= 3)
	{
		ft_printf("No enough space for enemies\n");
		return ;
	}
	spawn_enemies_2(data);
	init_enemies(data);
	render_enemies(data);
}
