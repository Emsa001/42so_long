/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:43:51 by escura            #+#    #+#             */
/*   Updated: 2024/01/24 14:14:27 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	print_player_map(const t_scene *scene)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("\n");
	while (i < scene->player_map_rows)
	{
		j = 0;
		while (j < scene->player_map_cols)
		{
			ft_printf("%c ", scene->player_map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

void	print_full_map(const t_scene *scene)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("\n");
	while (i < scene->rows)
	{
		j = 0;
		while (j < scene->cols)
		{
			ft_printf("%c", scene->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}
