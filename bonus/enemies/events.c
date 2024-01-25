/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:30:55 by escura            #+#    #+#             */
/*   Updated: 2024/01/25 18:13:56 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	kill_player(t_data *data)
{
	data->player->alive = 0;
	data->player->texture = 0;
	data->player->texture_add = 10;
	data->scene->text = ft_strdup("You died!");
}

t_player	*find_enemy(t_data *data, int x, int y)
{
	int			i;
	t_player	*enemy;

	i = 0;
	while (i < data->scene->enemies_alive)
	{
		enemy = data->enemy[i++];
		if (enemy->x == x && enemy->y == y)
			return (enemy);
	}
	return (NULL);
}

void	kill_enemy(t_data *data, int x, int y)
{
	t_player	*player;
	t_player	*enemy;
	t_scene		*scene;

	player = data->player;
	enemy = find_enemy(data, x, y);
	if (enemy == NULL)
		return ;
	scene = data->scene;
	if (!enemy->alive)
		return ;
	scene->map[x][y] = 'x';
	enemy->texture = 0;
	enemy->texture_add = 4;
	enemy->alive = 0;
	data->scene->text = ft_strdup("You killed an enemy!");
}
