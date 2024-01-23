/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_map_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:14:29 by escura            #+#    #+#             */
/*   Updated: 2024/01/23 00:05:02 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "./alias.h"

static void	set_player_map_4(t_data *data, t_vars *vars, t_temp *t_vars)
{
	t_scene	*scene;
	int		temp_x;
	int		temp_y;
	char	*block;

	scene = data->scene;
	while (t_vars->j < vars->cols)
	{
		temp_x = t_vars->i + vars->start_x;
		temp_y = t_vars->j + vars->start_y;
		block = &scene->player_map[t_vars->i][t_vars->j];
		if (vars->cols <= 20)
			*block = scene->map[temp_x][temp_y];
		else
		{
			if (temp_x < vars->end_x && temp_y < vars->end_y)
				*block = scene->map[temp_x][temp_y];
			else
				*block = ' ';
		}
		t_vars->j++;
	}
}

static int	set_player_map_3(t_data *data, t_vars *vars, t_temp *t_vars)
{
	while (t_vars->i < vars->rows)
	{
		data->scene->player_map[t_vars->i] = (char *)ft_calloc(1, vars->cols
				* sizeof(char));
		if (data->scene->player_map[t_vars->i] == NULL)
			return (0);
		t_vars->j = 0;
		set_player_map_4(data, vars, t_vars);
		t_vars->i++;
	}
	return (1);
}

static void	check_errors(t_data *data, t_vars *vars, t_temp *temp_vars)
{
	if (!data->scene->player_map)
	{
		free(vars);
		free(temp_vars);
		ft_printf("Error: Failed to allocate memory for player_map\n");
		exit(1);
	}
	if (set_player_map_3(data, vars, temp_vars) == 0)
	{
		free(vars);
		free(temp_vars);
		ft_printf("Error: Failed to allocate memory for player_map\n");
		exit(1);
	}
}

static void	set_player_map_2(t_data *data, t_vars *vars)
{
	int		i;
	int		j;
	int		temp_x;
	int		temp_y;
	t_temp	*temp_vars;

	temp_vars = (t_temp *)ft_calloc(1, sizeof(t_temp));
	if (temp_vars == NULL)
	{
		free(vars);
		ft_printf("Error: Failed to allocate memory for temp_vars\n");
		exit(1);
	}
	data->scene->player_map = (char **)ft_calloc(1, vars->rows
			* sizeof(char *));
	check_errors(data, vars, temp_vars);
	free(temp_vars);
}

void	set_player_map(t_data *data)
{
	t_scene	*scene;
	t_vars	*vars;

	scene = data->scene;
	vars = (t_vars *)ft_calloc(1, sizeof(t_vars));
	if (vars == NULL)
	{
		ft_printf("Error: Failed to allocate memory for vars\n");
		exit(1);
	}
	if (scene->player_map != NULL)
		free_player_map(scene);
	init_player_map_vars(data, vars);
	set_player_map_2(data, vars);
	free(vars);
}
