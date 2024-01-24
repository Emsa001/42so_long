/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:50:17 by escura            #+#    #+#             */
/*   Updated: 2024/01/24 19:34:09 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	player_controls(int keycode, t_data *data, int *x, int *y)
{
	t_player	*player;

	player = data->player;
	if (keycode == 2)
	{
		player->texture_add = 0;
		player->direction = 0;
		(*y)++;
	}
	else if (keycode == 0)
	{
		player->texture_add = 5;
		player->direction = 1;
		(*y)--;
	}
	else if (keycode == 13)
		(*x)--;
	else if (keycode == 1)
		(*x)++;
	else if(keycode == 49)
		spawn_bomb(data, *x, *y);
	player->running = 1;
}

static void	move_player_hook(int keycode, t_data *data)
{
	const t_player	*player = data->player;
	int				x;
	int				y;

	x = player->x;
	y = player->y;
	if(player->alive == 0)
		return;
	player_controls(keycode, data, &x, &y);
	if ((x != player->x || y != player->y) && check_if_safe(data, x, y)
		&& data->game_over == 0)
	{
		if (check_objectives(data, x, y) != 1)
			return ;
		data->scene->map[player->x][player->y] = '0';
		data->player->x = x;
		data->player->y = y;
		data->player->moves++;
		data->scene->map[x][y] = 'P';
		render_player_view(*data, 0);
		data->player->running = 0;
	}
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		free_data(data);
	if (data->game_over == 1)
		return (-1);
	move_player_hook(keycode, data);
	return (-1);
}
