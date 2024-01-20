/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:17:22 by escura            #+#    #+#             */
/*   Updated: 2024/01/20 16:47:05 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

	render_static(data);

	// mlx_do_sync(data.mlx);
	mlx_loop(data.mlx);
	return (0);
}
