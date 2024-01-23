/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:00:13 by escura            #+#    #+#             */
/*   Updated: 2024/01/23 16:05:37 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "./alias.h"

void	clear_visited(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->rows)
	{
		j = 0;
		while (j < vars->cols)
		{
			vars->visited[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	free_memory(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->rows)
	{
		free(vars->map[i]);
		free(vars->visited[i]);
		i++;
	}
	free(vars->map);
	free(vars->visited);
	free(vars);
	return (0);
}

int	check_if_can_walk(t_vars *vars, int x, int y)
{
	int		**visited;
	int		rows;
	int		cols;
	char	**map;
	int		i;

	visited = vars->visited;
	rows = vars->rows;
	cols = vars->cols;
	map = vars->map;
	i = 0;
	while (i < 3)
	{
		if (map[x][y] == vars->static_tiles[i++])
			return (0);
	}
	if (x < 0 || y < 0 || x >= rows || y >= cols || visited[x][y])
		return (0);
	return (1);
}

int	count_converted(t_vars *vars, char to_find)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < vars->rows)
	{
		j = 0;
		while (j < vars->cols)
		{
			if (vars->map[i][j] == to_find)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
