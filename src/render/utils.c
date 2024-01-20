/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:38:25 by escura            #+#    #+#             */
/*   Updated: 2024/01/20 18:39:24 by escura           ###   ########.fr       */
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

    int x = data->scene->exit_x * data->scene->block_size;
    int y = data->scene->exit_y * data->scene->block_size;

    load_image("/Users/escura/course/projects/ring3/so_long/textures/victory/chest_open.xpm", *data, x, y);
}

void show_text(t_data *data, char *message)
{
    char **split = ft_split(message, '\n');

    int i = 0;
    while(split[i])
    {
        int x = (data->scene->cols / 2) * data->scene->block_size;
        int y = (data->scene->rows - 1) * data->scene->block_size;

        int length = ft_strlen(split[i]);
        if(length > 10)
            x -= (length * 3);

        printf("x: %d\n", x);
        printf("y: %d\n", y);

        mlx_string_put(data->mlx, data->win, x, y += 15, 0x00f59e0b, split[i]);
        free(split[i++]);
    }
	free(split);
    i = 0;

    data->scene->rerender = (int **)malloc(sizeof(int *) * 8 + 1);
    while(i < 8){
        data->scene->rerender[i] = (int *)malloc(sizeof(int) * 2);
        data->scene->rerender[i][0] = (data->scene->rows - 1);
        data->scene->rerender[i][1] = (data->scene->cols / 2) - 3 + i;
        i++;
    }
    data->scene->rerender[i] = NULL;
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
