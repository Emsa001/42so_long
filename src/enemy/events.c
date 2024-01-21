/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:37:43 by escura            #+#    #+#             */
/*   Updated: 2024/01/21 22:56:31 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_enemy *find_enemy(t_data *data, int x, int y)
{
    int i = 0;
    int enemies = count(data->scene->map_string, 'X');
    while(i < enemies){
        t_enemy *enemy = data->enemy[i++];
        if(enemy->x == x && enemy->y == y)
            return enemy;
    }
    return NULL;
}

void kill_enemy(t_data *data, int x, int y)
{
    t_player *player = data->player;
    t_enemy *enemy = find_enemy(data, x, y);
    if(enemy == NULL)
        return;
    t_scene *scene = data->scene;

    if(!enemy->alive)
        return;
    scene->map[x][y] = '-';

    enemy->alive = 0;
    show_text(data, "I killed the goblin!\n");
    player->attack = 0;
    render_dynamic(*data);
    // init_enemy(data);    
}