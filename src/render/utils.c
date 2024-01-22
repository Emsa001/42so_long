/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:38:25 by escura            #+#    #+#             */
/*   Updated: 2024/01/22 19:57:02 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void show_text(t_data *data, char *message)
{
    const t_textures *textures = data->textures;
    int center_x = (data->scene->player_map_cols / 2) * data->scene->block_size;
    int center_y = (data->scene->player_map_rows - 1) * data->scene->block_size;
    char **split = ft_split(message, '\n');

    render_player_view(*data,19);
    int i = 0;
    while(split[i])
    {
        int length = ft_strlen(split[i]);
        center_x -= (length * 4);

        mlx_string_put(data->mlx, data->win, center_x, center_y += 15, 0x00f59e0b, split[i]);
        free(split[i++]);
    }
	free(split);

    if(data->scene->text != NULL){
        free(data->scene->text);
        data->scene->text = NULL;
    }
}

void load_image(char *path, t_data data, int x, int y)
{
    void *img;
    int img_width;
    int img_height;
    img = mlx_xpm_file_to_image(data.mlx, path, &img_width, &img_height);
    if (img == NULL) {
        printf("Error: failed to load image: %s\n", path);
        free_data(&data);
    }

    mlx_put_image_to_window(data.mlx, data.win, img, x, y);
    mlx_destroy_image(data.mlx, img);
}
