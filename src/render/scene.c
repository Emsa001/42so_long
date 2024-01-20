/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:26:31 by escura            #+#    #+#             */
/*   Updated: 2024/01/20 22:00:42 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void render_static(t_data data)
{
    const t_scene *scene = data.scene;
    const t_textures *textures = data.textures;
    const t_player *player = data.player;
    const t_enemy *enemy = data.enemy;
    
    int i = 0;
    while (i < scene->rows)
    {
        int j = 0;
        while (j < scene->cols)
        {
            char block = scene->map[i][j];
            if(block != '1')
                load_image(textures->floor, data, j * scene->block_size, i * scene->block_size);
            else if (block == '1')
                load_image(textures->wall, data, j * scene->block_size, i * scene->block_size);

            if (block == 'C')
                load_image(textures->collectible[0], data, j * scene->block_size, i * scene->block_size);
            else if(block == 'S')
                load_image(textures->collectible[1], data, j * scene->block_size, i * scene->block_size);
            else if (block == 'E')
                load_image(textures->exit, data, j * scene->block_size, i * scene->block_size);
            else if (block == 'P')
                load_image(player->texture, data, j * scene->block_size, i * scene->block_size);
            if (block == 'X')
                load_image(enemy->texture, data, j * scene->block_size, i * scene->block_size);
            j++;
        }
        i++;
    }
}

void render_dynamic(t_data data)
{
    const t_scene *scene = data.scene;
    const t_textures *textures = data.textures;
    const t_player *player = data.player;
    const t_enemy *enemy = data.enemy;
    
    printf("\n\n");
    print_map(scene);

    if(find_player(scene) == 0)
        kill_player(&data);

    int i = 0;
    while (i < scene->rows)
    {
        int j = 0;
        while (j < scene->cols)
        {
            char block = scene->map[i][j];
            if (block == '-' || block == 'P')
                load_image(textures->floor, data, j * scene->block_size, i * scene->block_size);
            
            if (block == 'P')
                load_image(player->texture, data, j * scene->block_size, i * scene->block_size);
            
            if (block == 'X')
                load_image(enemy->texture, data, j * scene->block_size, i * scene->block_size);
            j++;
        }
        i++;
    }
    render_moves(data);
}

void render_moves(t_data data)
{
    t_scene *scene = data.scene;
    const t_textures *textures = data.textures;
    const t_player *player = data.player;
    
    char *moves = ft_itoa(player->moves);
    int cols = 4;

    while(cols--){
        load_image(textures->wall, data, cols*scene->block_size, 0);
    }

    mlx_string_put(data.mlx, data.win, 5, 5, 0x00f59e0b, "Moves:");
    mlx_string_put(data.mlx, data.win, 70, 5, 0x00f59e0b, moves);
    free(moves);
}

void re_render(t_data *data)
{
    t_scene *scene = data->scene;
    const t_textures *textures = data->textures;
    const t_player *player = data->player;

    int i = 0;
    while (scene->rerender[i])
    {
        int x = scene->rerender[i][0];
        int y = scene->rerender[i][1];
        char block = scene->map[x][y];

        if (block == '1')
            load_image(textures->wall, *data, y * scene->block_size, x * scene->block_size);
        else
            load_image(textures->floor, *data, y * scene->block_size, x * scene->block_size);

        if (block == 'C')
                load_image(textures->collectible[1], *data, y * scene->block_size, x * scene->block_size);
        else if (block == 'E')
            load_image(textures->exit, *data, y * scene->block_size, x * scene->block_size);
        else if (block == 'P')
            load_image(player->texture, *data, y * scene->block_size, x * scene->block_size);
            

        free(scene->rerender[i++]);
    }
    free(scene->rerender);
    scene->rerender = NULL;
}
