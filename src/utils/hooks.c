/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:34:46 by escura            #+#    #+#             */
/*   Updated: 2024/01/19 18:52:56 by escura           ###   ########.fr       */
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
	int next_position;

	// d
	if(keycode == 2){
		next_position = current_position + 1;
		data->player_direction = 0;
	}	

	// a
	if(keycode == 0){
		next_position = current_position - 1;
		data->player_direction = 1;
	}

	// w
	if(keycode == 13){
		next_position = current_position - (data->mapCols) - 1;
	}

	// s
	if(keycode == 1){
		next_position = current_position + (data->mapCols) + 1;
	}

	char temp = data->map[next_position];

	if(data->map[next_position] != '1' && (keycode == 2 || keycode == 0 || keycode == 13 || keycode == 1))
	{
		if(find_position(data->map, 'E') == -1)
			return 0;

		if(temp == 'E' && count(data->map, 'C') > 0){
			if(data->text_shown == 0)
			{
				show_text(data,"I need to get\nall the potions!");
				data->text_shown = 1;
			}
			return 0;
		}
		if(data->text_shown == 1)
			data->text_shown = 0;
		data->moves_count++;
		data->map[next_position] = 'P';
		data->map[current_position] = '-';
		render_scene(data);
		render_moves(*data);
		data->map[current_position] = '0';

		if(temp == 'C')
			show_text(data,"Amazing!\nPotion collected!");
		else if(temp == 'E')
			victory(data);
	}

	return (-1);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	// printf("You've pressed: %d\n", button);
	// printf("Mouse position: %d, %d\n", x, y);
	return (0);
}
