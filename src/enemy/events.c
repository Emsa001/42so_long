/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:37:43 by escura            #+#    #+#             */
/*   Updated: 2024/01/20 21:44:44 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void kill_player(t_data *data)
{
    t_player *player = data->player;
    t_scene *scene = data->scene;

    data->game_over = 1;
    player->alive = 0;
    player->texture = data->textures->player[2];
    show_text(data, "You died! Press ESC to exit");
}

void kill_enemy(t_data *data)
{
    t_player *player = data->player;
    t_enemy *enemy = data->enemy;
    t_scene *scene = data->scene;
    enemy->alive = 0;
    show_text(data, "I killed the goblin!\n");
    player->attack = 0;
    render_dynamic(*data);
    init_enemy(data);    
}