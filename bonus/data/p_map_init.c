/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:49:22 by escura            #+#    #+#             */
/*   Updated: 2024/01/24 14:14:44 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"
#include "./alias.h"

static void	init_player_map_vars_2(t_data *data, t_vars *vars)
{
	if (vars->cols >= 20)
	{
		if (data->player->y - 10 >= 0)
			vars->start_y = data->player->y - 10;
		else
			vars->start_y = 0;
		if (data->player->y > data->scene->cols - 10)
			vars->start_y = data->scene->cols - 20;
		if (vars->start_y + 20 < data->scene->cols)
			vars->end_y = vars->start_y + 20;
		else
			vars->end_y = data->scene->cols;
		vars->cols = 20;
	}
}

static void	init_player_map_vars_3(t_data *data, t_vars *vars)
{
	if (vars->rows >= 20)
	{
		if (data->player->x - 10 >= 0)
			vars->start_x = data->player->x - 10;
		else
			vars->start_x = 0;
		if (data->player->x > data->scene->rows - 10)
			vars->start_x = data->scene->rows - 20;
		if (vars->start_x + 20 < data->scene->rows)
			vars->end_x = vars->start_x + 20;
		else
			vars->end_x = data->scene->rows;
		vars->rows = 20;
	}
}

void	init_player_map_vars(t_data *data, t_vars *vars)
{
	vars->rows = data->scene->player_map_rows;
	vars->cols = data->scene->player_map_cols;
	vars->start_x = 0;
	vars->start_y = 0;
	vars->end_x = data->scene->player_map_rows;
	vars->end_y = data->scene->player_map_cols;
	init_player_map_vars_2(data, vars);
	init_player_map_vars_3(data, vars);
}
