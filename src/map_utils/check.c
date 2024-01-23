/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:44:49 by escura            #+#    #+#             */
/*   Updated: 2024/01/23 16:10:58 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "./alias.h"

static int	check_tiles(char tile)
{
	if (tile != '1' && tile != '0' && tile != 'C' && tile != 'E' && tile != 'P')
		return (0);
	return (1);
}

static int	check_grid(char **map, int rows)
{
	int			i;
	int			j;
	const int	length = ft_strlen(map[0]);

	i = 0;
	j = 0;
	while (i < rows)
	{
		if (map[i][j] != '1')
			return (0);
		while (map[i][j] != '\0')
			if (check_tiles(map[i][j++]) == 0)
				return (0);
		if (map[i][j - 1] != '1' || j != length)
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

static int	clean_up(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->rows)
		free(vars->map[i++]);
	free(vars->map);
	free(vars);
	return (0);
}

int	check_if_correct(char *map_str)
{
	t_vars	*vars;

	vars = ft_calloc(1, sizeof(t_vars));
	if (vars == NULL)
		return (0);
	convert_map(map_str, &vars->map, &vars->rows, &vars->cols);
	if (check_grid(vars->map, vars->rows) == 0)
		return (clean_up(vars));
	if (is_possible(vars) == 0)
		return (0);
	return (1);
}

int	count(char *map, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i] != '\0')
	{
		if (map[i] == c)
			count++;
		i++;
	}
	return (count);
}
