/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:13:21 by escura            #+#    #+#             */
/*   Updated: 2024/01/23 16:19:38 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "./alias.h"

static int	dfs(t_vars *vars, int x, int y, char to_find)
{
	if (check_if_can_walk(vars, x, y) == 0)
		return (0);
	if (vars->map[x][y] == to_find)
	{
		if (to_find == 'C')
			vars->map[x][y] = 'V';
		return (1);
	}
	vars->visited[x][y] = 1;
	return (dfs(vars, x - 1, y, to_find) || dfs(vars, x + 1, y, to_find)
		|| dfs(vars, x, y - 1, to_find) || dfs(vars, x, y + 1, to_find));
}

static void	is_possible_2(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->rows)
	{
		j = 0;
		while (j < vars->cols)
		{
			if (vars->map[i][j] == 'P')
			{
				vars->px = i;
				vars->py = j;
				break ;
			}
			j++;
		}
		i++;
	}
	vars->static_tiles[0] = '1';
	vars->static_tiles[1] = ' ';
	vars->static_tiles[2] = ' ';
}

static void	set_collectibles(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->rows)
	{
		j = 0;
		while (j < vars->cols)
		{
			if (vars->map[i][j] == 'V')
				vars->map[i][j] = 'C';
			j++;
		}
		i++;
	}
}

int	is_possible(t_vars *vars)
{
	int	i;

	vars->visited = (int **)ft_calloc(1, vars->rows * sizeof(int *));
	if (vars->visited == NULL)
		return (0);
	i = 0;
	while (i < vars->rows)
	{
		vars->visited[i] = ft_calloc(vars->cols, sizeof(int));
		if (vars->visited[i++] == NULL)
			return (free_memory(vars));
	}
	is_possible_2(vars);
	if (dfs(vars, vars->px, vars->py, 'E') == 0)
		return (free_memory(vars));
	clear_visited(vars);
	vars->static_tiles[1] = 'E';
	while (count_converted(vars, 'C') > 0)
	{
		clear_visited(vars);
		if (dfs(vars, vars->px, vars->py, 'C') == 0)
			return (free_memory(vars));
	}
	free_memory(vars);
	return (1);
}
