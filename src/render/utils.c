/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:38:25 by escura            #+#    #+#             */
/*   Updated: 2024/01/23 18:14:58 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	show_text(t_data *data, char *message)
{
	const int	center_x = (data->scene->player_map_cols / 2) \
	* data->scene->block_size;
	const int	center_y = (data->scene->player_map_rows - 1) \
	* data->scene->block_size;
	const int	length = ft_strlen(message);

	render_player_view(*data, 19);
	mlx_string_put(data->mlx, data->win, center_x - length * 4, center_y + 15,
		0x00f59e0b, message);
	if (data->scene->text != NULL)
		free(data->scene->text);
	data->scene->text = NULL;
}

void	announce(t_data *data, char *message)
{
	const t_textures	*textures = data->textures;
	const t_player		*player = data->player;
	const t_scene		*scene = data->scene;
	const int			center_x = (data->width / 2) - 30;
	const int			center_y = (data->height / 2) - 30;

	render_player_view(*data, 19);
	load_image(textures->floor, *data, player->y * scene->block_size, player->x
		* scene->block_size);
	load_image(textures->message[1], *data, center_x - 60, center_y - 20);
	mlx_string_put(data->mlx, data->win, center_x, center_y, 0x000000,
		message);
}

void	load_image(char *path, t_data data, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(data.mlx, path, &img_width, &img_height);
	if (img == NULL)
	{
		printf("Error: failed to load image: %s\n", path);
		free_data(&data);
	}
	mlx_put_image_to_window(data.mlx, data.win, img, x, y);
	mlx_destroy_image(data.mlx, img);
}
