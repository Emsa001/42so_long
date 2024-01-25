/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bomb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:27:43 by escura            #+#    #+#             */
/*   Updated: 2024/01/25 18:13:30 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	spawn_bomb(t_data *data, int x, int y)
{
	const int	bomb_id = data->player->max_bombs - data->player->bombs;

	if (data->player->bombs == 0)
		return ;
	data->player->allbombs[bomb_id]->x = x;
	data->player->allbombs[bomb_id]->y = y;
	data->player->allbombs[bomb_id]->timer = 8;
	data->player->bombs--;
}

static void	explode_bomb_3(t_data *data, int temp_x, int temp_y)
{
	if (data->scene->map[temp_x][temp_y] != 'C'
		&& data->scene->map[temp_x][temp_y] != 'E')
	{
		if (data->scene->map[temp_x][temp_y] == 'X')
			kill_enemy(data, temp_x, temp_y);
		else if (data->scene->map[temp_x][temp_y] == 'P')
			kill_player(data);
		data->scene->map[temp_x][temp_y] = 'B';
	}
}

static void	explode_bomb_2(t_data *data, t_bomb *bomb, int i)
{
	int	j;
	int	temp_x;
	int	temp_y;

	while (i <= bomb->x + 1)
	{
		j = bomb->y - 1;
		while (j <= bomb->y + 1)
		{
			temp_x = i;
			temp_y = j;
			if (temp_x < 1)
				temp_x = 1;
			if (temp_y < 1)
				temp_y = 1;
			if (temp_x >= data->scene->rows - 1)
				temp_x = data->scene->rows - 2;
			if (temp_y >= data->scene->cols - 1)
				temp_y = data->scene->cols - 2;
			explode_bomb_3(data, temp_x, temp_y);
			j++;
		}
		i++;
	}
}

static void	explode_bomb(t_data *data, int id)
{
	t_scene	*scene;
	t_bomb	*bomb;

	scene = data->scene;
	bomb = data->player->allbombs[id];
	scene->boom_animation = 0;
	bomb->exploded = 1;
	bomb->timer = -1;
	explode_bomb_2(data, bomb, bomb->x - 1);
	scene->map[bomb->x][bomb->y] = 'B';
	render_player_view(*data, 0);
}

void	explode_bombs(t_data *data)
{
	t_player	*player;
	int			i;
	int			timer;
	t_bomb		*bomb;

	player = data->player;
	i = player->max_bombs - player->bombs - 1;
	while (i < player->max_bombs)
	{
		if (i < 0)
			return ;
		timer = player->allbombs[i]->timer;
		bomb = player->allbombs[i];
		if (timer != -1 && bomb->exploded == 0)
		{
			load_image(data->textures->bomb[timer / 2], *data, bomb->y
				* data->scene->block_size, bomb->x * data->scene->block_size);
			if (timer > 0)
				player->allbombs[i]->timer--;
			else if (timer == 0)
				explode_bomb(data, i);
		}
		i++;
	}
}
