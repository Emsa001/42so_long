/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:13:21 by escura            #+#    #+#             */
/*   Updated: 2024/01/23 00:54:01 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "./alias.h"

static void	free_memory(t_vars *vars)
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
}

static int	dfs(t_vars *vars, int x, int y)
{
	int		**visited;
	int		rows;
	int		cols;
	char	**map;

	visited = vars->visited;
	rows = vars->rows;
	cols = vars->cols;
	map = vars->map;
	if (x < 0 || y < 0 || x >= rows || y >= cols || visited[x][y]
		|| map[x][y] == '1' || map[x][y] == ' ')
		return (0);
	if (map[x][y] == 'E')
		return (1);
	visited[x][y] = 1;
	return (dfs(vars, x - 1, y) || dfs(vars, x + 1, y) || dfs(vars, x, y - 1)
		|| dfs(vars, x, y + 1));
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
}

int	is_possible(t_vars *vars)
{
	int	i;
	int	result;

	vars->visited = (int **)ft_calloc(1, vars->rows * sizeof(int *));
	if (vars->visited == NULL)
		return (0);
	i = 0;
	while (i < vars->rows)
	{
		vars->visited[i] = ft_calloc(vars->cols, sizeof(int));
		if (vars->visited[i++] == NULL)
		{
			free_memory(vars);
			return (0);
		}
	}
	is_possible_2(vars);
	result = dfs(vars, vars->px, vars->py) == 1;
	free_memory(vars);
	return (result);
}
