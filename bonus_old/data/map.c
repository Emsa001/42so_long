/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:14:29 by escura            #+#    #+#             */
/*   Updated: 2024/01/24 14:16:51 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus_old.h"

void set_real_position(t_data *data, int *x_pos, int *y_pos, char c)
{
	const t_scene *scene = data->scene;

	int x = 0;
	int y = 0;
	while(scene->map[x][y] != c)
	{
		y++;
		if(y == scene->cols)
		{
			y = 0;
			x++;
		}
	}

	*x_pos = x;
	*y_pos = y;
}

void print_map(const t_scene *scene)
{
	printf("\n");
	for(int i = 0; i < scene->rows; i++)
    {
        for(int j = 0; j < scene->cols; j++)
            printf("%c", scene->map[i][j]);
        printf("\n");
    }
	printf("\n");
}