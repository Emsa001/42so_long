/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:09:01 by escura            #+#    #+#             */
/*   Updated: 2024/01/19 18:32:31 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void victory(t_data *data)
{
    int win_width = data->width;
    int win_height = data->height;

    // Calculate the center of the screen
    int center_x = (win_width / 2) - 30;
    int center_y = (win_height / 2) - 30;

    // Print "You Win" at the center of the screen
    mlx_string_put(data->mlx, data->win, center_x, center_y, 0xFFFFFF, "You Win");

    load_image("/Users/escura/course/projects/ring3/so_long/textures/victory/chest_open.xpm", *data, data->exit_x, data->exit_y);

}

void show_text(t_data *data, char *message)
{
    int x = data->player_x - 1.5*data->block_size;
    int y = data->player_y - data->block_size;
    char **split = ft_split(message, '\n');
    while(*split)
    {
        mlx_string_put(data->mlx, data->win, x, y, 0x00f59e0b, *split);
        free(*split);
        split++;
        y += 15;
    }
    
    data->rerender = 1;
}

