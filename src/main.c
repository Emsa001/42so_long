/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:17:22 by escura            #+#    #+#             */
/*   Updated: 2024/01/23 00:10:32 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	render_next_frame(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (data->game_over == 1)
		return (-1);
	if (data->scene->text != NULL)
		show_text(data, data->scene->text);
	if (data->frame_update == 1000)
	{
		if (player->texture >= 3)
			player->texture = 0;
		else
			player->texture++;
		animation_update(*data);
	}
	if (data->frame_update < 2000)
	{
		data->frame_update++;
		return (-1);
	}
	data->frame_update = 0;
	return (-1);
}

int	main(int nb, char **args)
{
	t_data	data;
	char	*map;

	if (args[1] == NULL)
		map = read_map("./maps/labirynt2.ber");
	else
		map = read_map(args[1]);
	if (check_if_correct(map) == 0)
	{
		ft_printf("\nError with map. Possible Problems:\n");
		ft_printf("- Invalid Path\n- Memory allocation (unlikely)\n\n");
		free(map);
		exit(1);
	}
	init_data(&data, map);
	mlx_hook(data.win, 2, 0, key_hook, &data);
	mlx_hook(data.win, 17, 0, free_data, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	render_player_view(data, 0);
	mlx_loop(data.mlx);
	return (0);
}
