/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:06:16 by escura            #+#    #+#             */
/*   Updated: 2024/01/29 12:22:02 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	go_up(t_data *data, t_player *enemy)
{
	t_scene	*scene;
	char	next_position;

	scene = data->scene;
	next_position = scene->map[enemy->x - 1][enemy->y];
	if (next_position == 'P')
	{
		kill_player(data);
		return ;
	}
	if (next_position == '1' || next_position == 'E' || next_position == 'C')
	{
		enemy->direction = 1;
		return ;
	}
	scene->map[enemy->x][enemy->y] = '0';
	enemy->x--;
	scene->map[enemy->x][enemy->y] = 'X';
}

void	go_down(t_data *data, t_player *enemy)
{
	t_scene	*scene;
	char	next_position;

	scene = data->scene;
	next_position = scene->map[enemy->x + 1][enemy->y];
	if (next_position == 'P')
	{
		kill_player(data);
		return ;
	}
	if (next_position == '1' || next_position == 'E' || next_position == 'C')
	{
		enemy->direction = 0;
		return ;
	}
	scene->map[enemy->x][enemy->y] = '0';
	enemy->x++;
	scene->map[enemy->x][enemy->y] = 'X';
}

void	go_vertical(t_data *data, t_player *enemy, int x)
{
	t_scene	*scene;
	char	next_position;

	scene = data->scene;
	next_position = scene->map[enemy->x + x][enemy->y];
	if (next_position == 'P')
	{
		kill_player(data);
		return ;
	}
	if (next_position == '1' || next_position == 'E' || next_position == 'C')
	{
		enemy->direction = x == 1;
		return ;
	}
	scene->map[enemy->x][enemy->y] = '0';
	enemy->x += x;
	scene->map[enemy->x][enemy->y] = 'X';
}

int	move_enemy(t_data *data, t_player *enemy)
{
	t_scene	*scene;
	int		x;
	int		y;

	scene = data->scene;
	x = enemy->x;
	y = enemy->y;
	enemy->prev_x = x;
	enemy->prev_y = y;
	if (enemy->alive == 0)
		return (0);
	if (enemy->direction == 0)
		go_vertical(data, enemy, 1);
	else
		go_vertical(data, enemy, -1);
	return (-1);
}

void	move_enemies(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->scene->enemies_alive)
	{
		if (data->enemy[i]->texture >= 3 && data->enemy[i]->alive == 1)
			data->enemy[i]->texture = 0;
		else
			data->enemy[i]->texture++;
		if (rnd(1, 4) == 2)
			move_enemy(data, data->enemy[i]);
		i++;
	}
	render_player_view(*data, 0);
}
