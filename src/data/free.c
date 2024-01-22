/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:53:48 by escura            #+#    #+#             */
/*   Updated: 2024/01/22 19:35:11 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	free_scene(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->rows)
		free(scene->map[i++]);
	free(scene->map);
	free(scene->map_string);
	free(scene);
}

void	free_rerender(int **rerender)
{
	int	i;

	i = 0;
	if (!rerender)
		return ;
	while (rerender[i])
		free(rerender[i++]);
	free(rerender);
}

int	free_data(t_data *data)
{
	free_player_map(data->scene);
	free(data->player);
	free_rerender(data->scene->rerender);
	free_scene(data->scene);
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}
