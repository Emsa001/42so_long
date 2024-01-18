/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:34:46 by escura            #+#    #+#             */
/*   Updated: 2024/01/18 18:20:46 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	key_hook(int keycode, t_data *data)
{
	// printf("You've pressed: %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
    
	int current_position = find_position(data->map, 'P');
	if(find_position(data->map, 'E') == -1)
		return 0;

	if(keycode == 2){
		int right_element = data->map[current_position + 1];
		if(right_element != '1'){
			data->map[current_position + 1] = 'P';
			data->map[current_position] = '0';
			data->player_direction = 0;
			render_scene(*data);
			printf("moving right\n");
		}
	}

	if(keycode == 0){
		int left_element = data->map[current_position - 1];
		if(left_element != '1'){
			data->map[current_position - 1] = 'P';
			data->map[current_position] = '0';
			data->player_direction = 1;
			render_scene(*data);
			printf("moving left\n");
		}
	}

	if(keycode == 13){
		int top_element = data->map[current_position - (data->mapCols) - 1];
		if(top_element != '1'){
			data->map[current_position - data->mapCols - 1] = 'P';
			data->map[current_position] = '0';
			render_scene(*data);
			printf("moving up\n");
		}
	}

	if(keycode == 1){
		int down_element = data->map[current_position + (data->mapCols) + 1];
		if(down_element != '1'){
			data->map[current_position + data->mapCols + 1] = 'P';
			data->map[current_position] = '0';
			render_scene(*data);
			printf("moving down\n");
		}
	}

	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	// printf("You've pressed: %d\n", button);
	// printf("Mouse position: %d, %d\n", x, y);
	return (0);
}
