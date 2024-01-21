/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:26:31 by escura            #+#    #+#             */
/*   Updated: 2024/01/21 23:43:06 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void render_static(t_data data)
{
    const t_scene *scene = data.scene;
    const t_textures *textures = data.textures;
    const t_player *player = data.player;
    const t_enemy *enemy = data.enemy[0];
    
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
                load_image(textures->exit[scene->exit_texture], data, j * scene->block_size, i * scene->block_size);
            else if (block == 'P')
                load_image(textures->player[player->texture], data, j * scene->block_size, i * scene->block_size);
            if (block == 'X')
                load_image(textures->enemy[enemy->texture], data, j * scene->block_size, i * scene->block_size);
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
    const t_enemy *enemy = data.enemy[0];

    // printf("\n\n");
    // print_map(scene);

    if(data.game_over == 1 && player->alive == 1)
        return;

    int temp = 0;
    if(player->direction == 1)
        temp = 4;
    
    if(player->alive == 0)
        temp = 8;
    
    if(player->alive == 1 && data.game_over == 1)
        temp = 12;

    int i = 0;
    while (i < scene->rows)
    {
        int j = 0;
        while (j < scene->cols)
        {
            char block = scene->map[i][j];
            if(block == '-' || block == 'P' || block == 'X')
                load_image(textures->floor, data, j * scene->block_size, i * scene->block_size);
                
            if (block == '-')
                scene->map[i][j] = '0';
            
            if (block == 'P')
                load_image(textures->player[player->texture + temp], data, j * scene->block_size, i * scene->block_size);
            
            if (block == 'X')
                load_image(textures->enemy[enemy->texture], data, j * scene->block_size, i * scene->block_size);
            
            if(block == 'B'){
                load_image(textures->explosion[scene->boom_animation], data, j * scene->block_size, i * scene->block_size);
                if(scene->boom_animation == 4)
                    scene->map[i][j] = '0';
            }
            if(block == 'E' && scene->exit_texture == 1)
                load_image(textures->exit[scene->exit_texture], data, j * scene->block_size, i * scene->block_size);
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
    if(scene->rerender == NULL)
        return;

    while (scene->rerender[i] != NULL)
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
            load_image(textures->exit[scene->exit_texture], *data, y * scene->block_size, x * scene->block_size);
        else if (block == 'P')
            load_image(textures->player[player->texture], *data, y * scene->block_size, x * scene->block_size);
            

        free(scene->rerender[i++]);
    }
    if(scene->rerender != NULL)
        free(scene->rerender);
    scene->rerender = NULL;
}
