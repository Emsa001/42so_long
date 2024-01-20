/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:09:24 by escura            #+#    #+#             */
/*   Updated: 2024/01/20 21:18:09 by escura           ###   ########.fr       */
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
    t_scene *scene = data->scene;
    t_player *player = data->player;

    if(scene->map[x][y] == 'C')
    {
        show_text(data, "Great Job!\n");
        scene->collectibles--;
    }
    else if(scene->map[x][y] == 'S'){
        show_text(data, "I can use that sword to kill the goblin!\n");
        player->attack = 1;
    }
    else if(scene->map[x][y] == 'E')
    {
        if(scene->collectibles == 0){
            show_text(data,"Amaazing! Now I can leave this dungeon");
            victory(data);
        }
        else
            show_text(data,"I cannot leave any potions");
        return 0;
    }
    else if(scene->map[x][y] == 'X'){    
        kill_player(data);
        return 2;
    }

    return 1;
}