/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:14:27 by escura            #+#    #+#             */
/*   Updated: 2024/01/24 13:53:25 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	convert_map_3(char *map_str, char ***map, int row, int col)
{
	int	i;

	i = 0;
	while (map_str[i] != '\0')
	{
		if (map_str[i] == '\n')
		{
			(*map)[row][col] = '\0';
			row++;
			col = 0;
		}
		else
			(*map)[row][col++] = map_str[i];
		i++;
	}
	(*map)[row][col] = '\0';
}

static void	convert_map_2(char ***map, int *rows, int *cols)
{
	int	i;

	i = 0;
	*map = (char **)ft_calloc(1, *rows * sizeof(char *) + 1);
	if (*map == NULL)
		ft_error("Memory allocation failed for Map convertion\n");
	while (i < *rows)
	{
		(*map)[i] = (char *)ft_calloc(1, *cols * sizeof(char) + 1);
		if ((*map)[i] == NULL)
			ft_error("Memory allocation failed for Map convertion\n");
		i++;
	}
}

void	convert_map(char *map_str, char ***map, int *rows, int *cols)
{
	int	row;
	int	col;
	int	i;

	row = 0;
	col = 0;
	*rows = 1;
	*cols = 0;
	i = 0;
	while (map_str[i] != '\0')
	{
		if (map_str[i++] == '\n')
			(*rows)++;
		else if (*rows == 1)
			(*cols)++;
	}
	convert_map_2(map, rows, cols);
	convert_map_3(map_str, map, row, col);
}
