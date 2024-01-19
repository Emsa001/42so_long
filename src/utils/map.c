/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:14:29 by escura            #+#    #+#             */
/*   Updated: 2024/01/19 16:09:31 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	find_position(char *map, char c)
{
	int	i;

	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	set_real_positions(t_data *data)
{
	char *row, *map_copy;
	int i, j;
	map_copy = ft_strdup(data->map);
	row = ft_strtok(map_copy, "\n");
	for (i = 0; row != NULL; i++)
	{
		for (j = 0; j < ft_strlen(row); j++)
		{
			if (row[j] == 'E')
			{
				data->exit_x = j * data->block_size;
				data->exit_y = i * data->block_size;
			}
		}
		row = ft_strtok(NULL, "\n");
	}
	free(map_copy);
}

int map_get_rows(char *map)
{
	int rows = 1;
	int i = 0;
	while(map[i] != '\0')
	{
		if(map[i] == '\n')
			rows++;
		i++;
	}
	return rows;
}

int map_get_cols(char *map)
{
	int cols = 0;
	int i = 0;
	while(map[i] != '\0')
	{
		if(map[i] == '\n')
			break;
		cols++;
		i++;
	}
	return cols;
}