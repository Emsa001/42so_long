/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:35:07 by escura            #+#    #+#             */
/*   Updated: 2024/01/22 23:22:34 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

typedef struct s_vars
{
	int	rows;
	int	cols;
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
}		t_vars;

typedef struct s_temp
{
	int		i;
	int		j;
	int		temp_x;
	int		temp_y;
}		t_temp;

void	init_player_map_vars(t_data *data, t_vars *vars);