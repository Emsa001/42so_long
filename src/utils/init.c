/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:49:38 by escura            #+#    #+#             */
/*   Updated: 2024/01/19 16:13:13 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void init_data(t_data *data, char *map)
{
    data->mlx = mlx_init();
    if (!data->mlx)
    {
        printf("Failed to initialize mlx\n");
        exit(1);
    }

	data->map = (char *)malloc(ft_strlen(map) + 1);
	if(!data->map)
		exit(1);
	ft_strlcpy(data->map, map, ft_strlen(map) + 1);

	data->mapRows = map_get_rows(data->map);
    data->mapCols = map_get_cols(data->map);

    data->block_size = 50;
	data->rerender = 0;
    data->width = data->mapCols * data->block_size;
    data->height = data->mapRows * data->block_size;
	data->moves_count = 0;

	set_real_positions(data);

    data->win = mlx_new_window(data->mlx, data->width, data->height, "So Long");
    
    if (!data->win)
    {
        printf("Failed to create window\n");
        exit(1);
    }
}