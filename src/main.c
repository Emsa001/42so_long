/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:17:22 by escura            #+#    #+#             */
/*   Updated: 2024/01/22 13:54:50 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int random_number(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1;
    } else {
        low_num = max_num + 1; 
        hi_num = min_num;
    }

    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

void boom_animation(t_data *data)
{
	t_scene *scene = data->scene;
	
	if(data->frame_update % 500 == 0)
	{
		if(scene->boom_animation < 4)
			scene->boom_animation++;
	}

}

int render_next_frame(t_data *data)
{
	t_player *player = data->player;
	const int enemies = count(data->scene->map_string, 'X');
	int i = 0;

	if((player->alive == 0 && player->texture == 3) || (player->alive == 1 && data->game_over == 1))
		return -1;

	if(data->scene->boom_animation != -1 && data->scene->boom_animation < 4)
		boom_animation(data);


	if(data->frame_update == 1000){
		if(player->texture >= 3)
			player->texture = 0;
		else
			player->texture++;

		while(i < enemies){
			if(data->enemy[i]->alive == 0)
			{
				if(data->enemy[i]->texture <= 4)
					data->enemy[i]->texture++;
			}
			else{	
				if(data->enemy[i]->texture >= 3)
					data->enemy[i]->texture = 0;
				else
					data->enemy[i]->texture++;
			}

			render_enemy(data, data->enemy[i]);
			i++;
		}

		render_dynamic(*data);
	}
	
	if(data->frame_update < 2000){
		data->frame_update++;
		return -1;
	}

	data->frame_update = 0;
	
	if(player->alive == 0)
		return -1;

	i = 0;
	while(i < enemies){
		int x = random_number(0, 1);
		t_enemy *enemy = data->enemy[i++];
		if(x == 1)
			enemy_move(data, enemy);
	}

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
    mlx_hook(data.win, 17, 0, free_data, &data);

	mlx_loop_hook(data.mlx, render_next_frame, &data);
	render_static(data);
	
	// mlx_do_sync(data.mlx);
	mlx_loop(data.mlx);
	return (0);
}
