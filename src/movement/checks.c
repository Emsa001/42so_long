/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:09:24 by escura            #+#    #+#             */
/*   Updated: 2024/01/22 22:54:10 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	check_if_collectible(t_data *data, int x, int y)
{
	t_scene	*scene;

	scene = data->scene;
	if (scene->map[x][y] == 'C')
	{
		scene->collectibles--;
		if (scene->collectibles == 0)
		{
			scene->text = ft_strdup("Amaazing! Now I can leave this dungeon");
			scene->exit_texture = 1;
		}
		else
			scene->text = ft_strdup("Great Job!");
	}
}

int	check_objectives(t_data *data, int x, int y)
{
	const t_textures	*textures = data->textures;
	t_scene				*scene;
	t_player			*player;

	scene = data->scene;
	if (scene->map[x][y] == 'E')
	{
		if (scene->collectibles == 0)
			victory(data);
		else
			scene->text = ft_strdup("I cannot leave any potions");
		return (0);
	}
	check_if_collectible(data, x, y);
	return (1);
}

int	check_if_safe(t_data *data, int x, int y)
{
	t_scene	*scene;

	scene = data->scene;
	if (scene->map[x][y] == '1')
		return (0);
	return (1);
}
