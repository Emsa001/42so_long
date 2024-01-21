/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:09:24 by escura            #+#    #+#             */
/*   Updated: 2024/01/21 23:14:26 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int check_if_safe(t_data *data, int x, int y)
{
    t_scene *scene = data->scene;

    if(scene->map[x][y] == '1')
        return (0);

    return (1);
}

int check_objectives(t_data *data, int x, int y)
{
    const t_textures *textures = data->textures;

    t_scene *scene = data->scene;
    t_player *player = data->player;

    if(scene->map[x][y] == 'C')
    {
        scene->collectibles--;

        if(scene->collectibles == 0){
            show_text(data,"Amaazing! Now I can leave this dungeon");
            scene->exit_texture = 1;
        }else{
            show_text(data, "Great Job!\n");
        }
    }
    else if(scene->map[x][y] == 'S'){
        show_text(data, "I can use that sword to kill the goblin!\n");
        player->attack = 1;
    }
    else if(scene->map[x][y] == 'E')
    {
        if(scene->collectibles == 0){
            victory(data);
            return 1;
        }
        show_text(data,"I cannot leave any potions");
        return 0;
    }
    else if(scene->map[x][y] == 'X'){    
        kill_player(data);
        return 2;
    }

    return 1;
}

void victory(t_data *data)
{
    const t_textures *textures = data->textures;
    const t_player *player = data->player;
    const t_scene *scene = data->scene;

    int win_width = data->width;
    int win_height = data->height;

    // Calculate the center of the screen
    int center_x = (win_width / 2) - 30;
    int center_y = (win_height / 2) - 30;

    load_image(textures->message[1], *data, center_x - 60, center_y - 20);
    mlx_string_put(data->mlx, data->win, center_x, center_y, 0x000000, "You Win");
    show_text(data,"Press ESC to exit");
    load_image(textures->floor, *data, player->y * scene->block_size, player->x * scene->block_size);

    data->game_over = 1;
}

void kill_player(t_data *data)
{
    t_player *player = data->player;
    const t_textures *textures = data->textures;
    const t_scene *scene = data->scene;


    data->game_over = 1;
    player->alive = 0;
    player->texture = 0;
    render_dynamic(*data);

    int win_width = data->width;
    int win_height = data->height;

    // Calculate the center of the screen
    int center_x = (win_width / 2) - 30;
    int center_y = (win_height / 2) - 30;

    load_image(textures->message[1], *data, center_x - 53, center_y - 20);
    mlx_string_put(data->mlx, data->win, center_x, center_y, 0x000000, "Game Over");
    show_text(data, "You died! Press ESC to exit");
}