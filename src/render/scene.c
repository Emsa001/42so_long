/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:56:26 by escura            #+#    #+#             */
/*   Updated: 2024/01/19 17:52:25 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int render_rect(t_data data, t_rect rect)
{
    int i;
    int j;

    if (data.win == NULL)
        return (1);

    // Draw top and bottom borders
    for (j = rect.x; j < rect.x + rect.width; j++)
    {
        mlx_pixel_put(data.win, data.win, j, rect.y, rect.color);
        mlx_pixel_put(data.win, data.win, j, rect.y + rect.height - 1, rect.color);
    }

    // Draw left and right borders
    for (i = rect.y; i < rect.y + rect.height; i++)
    {
        mlx_pixel_put(data.win, data.win, rect.x, i, rect.color);
        mlx_pixel_put(data.win, data.win, rect.x + rect.width - 1, i, rect.color);
    }

    return (0);
}

void load_image(char *path, t_data data, int x, int y)
{
    void *img;
    int img_width;
    int img_height;
    img = mlx_xpm_file_to_image(data.mlx, path, &img_width, &img_height);
    if (img == NULL) {
        printf("Failed to load image\n");
        exit(1);
    }

    mlx_put_image_to_window(data.mlx, data.win, img, x, y);
    mlx_destroy_image(data.mlx, img);
}

void	render_scene(t_data *data)
{
    char *row, *map_copy;
    int i, j;

    if(data->rerender == 1){
        mlx_clear_window(data->mlx, data->win);
        render_static(*data);
        data->rerender = 0;
    }

    map_copy = ft_strdup(data->map);
    row = ft_strtok(map_copy, "\n");

    for(i = 0; row != NULL; i++) {
        for(j = 0; j < ft_strlen(row); j++) {
            if(row[j] == 'P') {
                load_image("/Users/escura/course/projects/ring3/so_long/textures/floor.xpm", *data, j*data->block_size, i*data->block_size);
                if(data->player_direction == 0){
                    load_image("/Users/escura/course/projects/ring3/so_long/textures/player_right.xpm", *data, j*data->block_size, i*data->block_size);
                }else{
                    load_image("/Users/escura/course/projects/ring3/so_long/textures/player_left.xpm", *data, j*data->block_size, i*data->block_size);
                }

                data->player_x = j*data->block_size;
                data->player_y = i*data->block_size;
            }
            else if(row[j] == '-'){
                load_image("/Users/escura/course/projects/ring3/so_long/textures/floor.xpm", *data, j*data->block_size, i*data->block_size);
            }
        }
        row = ft_strtok(NULL, "\n");
    }
    
    free(map_copy);
}

void render_static(t_data data)
{
    char *row, *map_copy;
    int i, j;

    map_copy = ft_strdup(data.map);
    row = ft_strtok(map_copy, "\n");

    for(i = 0; row != NULL; i++) {
        for(j = 0; j < ft_strlen(row); j++) {
            if(row[j] == '1')
                load_image("/Users/escura/course/projects/ring3/so_long/textures/wall.xpm", data, j*data.block_size, i*data.block_size);
            else
                load_image("/Users/escura/course/projects/ring3/so_long/textures/floor.xpm", data, j*data.block_size, i*data.block_size);

            if(row[j] == 'E') {
                load_image("/Users/escura/course/projects/ring3/so_long/textures/chest.xpm", data, j*data.block_size, i*data.block_size);
            }
            else if(row[j] == 'C')
                load_image("/Users/escura/course/projects/ring3/so_long/textures/potion_green.xpm", data, j*data.block_size, i*data.block_size);
        }
        row = ft_strtok(NULL, "\n");
    }

    free(map_copy);
}

void render_moves(t_data data)
{
    char *moves = ft_itoa(data.moves_count);
    int cols = 4;

    while(cols--){
        load_image("/Users/escura/course/projects/ring3/so_long/textures/wall.xpm", data, cols*data.block_size, 0);
    }

    mlx_string_put(data.mlx, data.win, 5, 5, 0x00f59e0b, "Moves:");
    mlx_string_put(data.mlx, data.win, 70, 5, 0x00f59e0b, moves);
    free(moves);
}