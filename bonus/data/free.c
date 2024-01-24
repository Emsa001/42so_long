/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:53:48 by escura            #+#    #+#             */
/*   Updated: 2024/01/24 20:56:36 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	free_bombs(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->player->max_bombs)
	{
		free(data->player->allbombs[i]);
		i++;
	}
	free(data->player->allbombs);
}

void	free_player_map(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < scene->player_map_rows)
	{
		free(scene->player_map[i]);
		i++;
	}
	free(scene->player_map);
}

void	free_scene(t_scene *scene)
{
	int	i;

	i = 0;
	free_player_map(scene);
	while (i < scene->rows)
		free(scene->map[i++]);
	free(scene->map);
	free(scene->text);
	free(scene->map_string);
	free(scene);
}

int	free_data(t_data *data)
{
	if (data->player != NULL)
	{
		free(data->player);
		free_bombs(data);
	}
	if (data->scene != NULL)
		free_scene(data->scene);
	if (data->textures != NULL)
		free(data->textures);
	if (data->win)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else
		ft_printf("Error opening window\n");
	exit(0);
	return (0);
}
