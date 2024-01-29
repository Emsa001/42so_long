/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:53:48 by escura            #+#    #+#             */
/*   Updated: 2024/01/29 12:09:42 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
	free(scene->text);
	free(scene->map);
	free(scene->map_string);
	free(scene);
}

int	free_data(t_data *data)
{
	if (data->player != NULL)
		free(data->player);
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
