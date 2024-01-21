/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:17:22 by escura            #+#    #+#             */
/*   Updated: 2024/01/21 15:25:28 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int render_next_frame(t_data *data)
{
	if(data->game_over == 1)
		return -1;
	if(data->frame_update < 5000){
		data->frame_update++;
		return -1;
	}

	data->frame_update = 0;
	enemy_move(data);
	return -1;
}

int	main(int nb, char **args)
{
	t_data data;
	char *map;
	if(args[1] == NULL)
		map = read_map("map.ber");
	else
		map = read_map(args[1]);

	init_data(&data, map);
	mlx_hook(data.win, 2, 0, key_hook, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);

	mlx_loop_hook(data.mlx, render_next_frame, &data);

	render_static(data);

	// mlx_do_sync(data.mlx);
	mlx_loop(data.mlx);
	return (0);
}
