/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bomb_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:11:07 by escura            #+#    #+#             */
/*   Updated: 2024/01/25 18:28:25 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static void	init_boms_2(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->player->bombs)
	{
		data->player->allbombs[i] = (t_bomb *)malloc(sizeof(t_bomb) + 1);
		if (data->player->allbombs[i] == NULL)
		{
			printf("Error: Failed to allocate memory for bomb %d\n", i);
			return ;
		}
		data->player->allbombs[i]->x = -1;
		data->player->allbombs[i]->y = -1;
		data->player->allbombs[i]->timer = -1;
		data->player->allbombs[i]->exploded = 0;
		i++;
	}
	data->textures->bomb[4] = "./textures/bomb/1.xpm";
	data->textures->bomb[3] = "./textures/bomb/2.xpm";
	data->textures->bomb[2] = "./textures/bomb/3.xpm";
	data->textures->bomb[1] = "./textures/bomb/4.xpm";
	data->textures->bomb[0] = "./textures/bomb/5.xpm";
}

void	init_bombs(t_data *data)
{
	if (data == NULL)
	{
		printf("Error: data is NULL\n");
		return ;
	}
	if (data->player->bombs < 0 || data->player->bombs > 100)
	{
		printf("Error: Invalid number of bombs\n");
		return ;
	}
	data->player->allbombs = (t_bomb **)malloc(data->player->bombs
			* sizeof(t_bomb) + 1);
	if (data->player->allbombs == NULL)
	{
		printf("Error: Failed to allocate memory for bombs\n");
		data->player->bombs = 0;
		return ;
	}
	init_boms_2(data);
}
