/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:26:31 by escura            #+#    #+#             */
/*   Updated: 2024/01/22 19:31:22 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void render_player_view(t_data data, int i)
{
    const t_scene *scene = data.scene;
    const t_textures *textures = data.textures;
    const t_player *player = data.player;
    
    set_player_map(&data);
    
    int temp_i = i;
    while (i < scene->player_map_rows)
    {
        int j = 0;
        while (j < scene->player_map_cols)
        {
            char block = scene->player_map[i][j];
            if(block == ' ')
                load_image(textures->empty, data, j * scene->block_size, i * scene->block_size);
            else{
                if(block == '1')
                    load_image(textures->wall, data, j * scene->block_size, i * scene->block_size);
                else
                    load_image(textures->floor, data, j * scene->block_size, i * scene->block_size);

                if (block == 'C')
                    load_image(textures->collectible[0], data, j * scene->block_size, i * scene->block_size);
                else if (block == 'E')
                    load_image(textures->exit[scene->exit_texture], data, j * scene->block_size, i * scene->block_size);
                else if (block == 'P')
                    load_image(textures->player[player->texture + player->direction * 4], data, j * scene->block_size, i * scene->block_size);
            }
            j++;
        }
        i++;
    }
    if(temp_i == 0)
        render_moves(data);
}

void render_moves(t_data data)
{
    t_scene *scene = data.scene;
    const t_player *player = data.player;
    
    char *moves = ft_itoa(player->moves);

    mlx_string_put(data.mlx, data.win, 5, 5, 0x00f59e0b, "Moves:");
    mlx_string_put(data.mlx, data.win, 70, 5, 0x00f59e0b, moves);
    ft_printf("Moves: %s\n", moves);
    free(moves);
}

void animation_update(t_data data)
{
    const t_scene *scene = data.scene;
    const t_textures *textures = data.textures;
    const t_player *player = data.player;

    int x;
    int y;
    set_pixel_position(&data,&x,&y, 'P');

    load_image(textures->floor, data, x, y);
    load_image(textures->player[player->texture + player->direction * 4], data, x, y);
}
