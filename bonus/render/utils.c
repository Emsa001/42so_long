/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:38:25 by escura            #+#    #+#             */
/*   Updated: 2024/01/22 14:54:12 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void show_text(t_data *data, char *message)
{
    const t_textures *textures = data->textures;
    int center_x = (data->scene->cols / 2) * data->scene->block_size;
    int center_y = (data->scene->rows - 1) * data->scene->block_size;
    char **split = ft_split(message, '\n');

    re_render(data);
    int i = 0;
    while(split[i])
    {
        int length = ft_strlen(split[i]);
        center_x -= (length * 4);

        mlx_string_put(data->mlx, data->win, center_x, center_y += 15, 0x00f59e0b, split[i]);
        free(split[i++]);
    }
	free(split);
    i = 0;

    data->scene->rerender = (int **)malloc(sizeof(int *) * 10 + 1);
    while(i < 10){
        data->scene->rerender[i] = (int *)malloc(sizeof(int) * 2);
        data->scene->rerender[i][0] = (data->scene->rows - 1);
        data->scene->rerender[i][1] = (data->scene->cols / 2) - 4 + i;
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
