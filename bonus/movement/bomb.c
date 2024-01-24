/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bomb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:27:43 by escura            #+#    #+#             */
/*   Updated: 2024/01/24 20:56:01 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void init_bombs(t_data *data)
{
    if(data == NULL)
    {
        printf("Error: data is NULL\n");
        return;
    }

    t_player *player = data->player;
    if(player->bombs < 0 || player->bombs > INT_MAX / sizeof(t_bomb))
    {
        printf("Error: Invalid number of bombs\n");
        return;
    }

    player->allbombs = (t_bomb **)malloc(player->bombs * sizeof(t_bomb) + 1);
    if(player->allbombs == NULL)
    {
        printf("Error: Failed to allocate memory for bombs\n");
        player->bombs = 0;
        return ;
    }

    int i = 0;
    while(i < player->bombs)
    {
        player->allbombs[i] = (t_bomb *)malloc(sizeof(t_bomb) + 1);
        if(player->allbombs[i] == NULL)
        {
            printf("Error: Failed to allocate memory for bomb %d\n", i);
            return ;
        }
        player->allbombs[i]->x = 0;
        player->allbombs[i]->y = 0;
        player->allbombs[i]->timer = -1;
        player->allbombs[i]->exploded = 0;
        i++;
    }
}

void	spawn_bomb(t_data *data, int x, int y)
{
    t_player *player = data->player;
    if(player->bombs == 0)
        return;
    
    const int bomb_id = player->max_bombs - player->bombs;

    player->allbombs[bomb_id]->x = x;
    player->allbombs[bomb_id]->y = y;
    player->allbombs[bomb_id]->timer = 3;
    player->bombs--;
}

static void explode_bomb(t_data *data, int id)
{
    t_scene *scene = data->scene;
    t_player *player = data->player;
    t_bomb *bomb = player->allbombs[id];

	scene->boom_animation = 0;
    bomb->exploded = 1;
    bomb->timer = -1;

    int x = bomb->x;
    int y = bomb->y;
    int radius = 1;
    for (int i = x - radius; i <= x + radius; i++) {
        for (int j = y - radius; j <= y + radius; j++) {
            int temp_x = i;
            int temp_y = j;

            if(temp_x < 1)
                temp_x = 1;
            if(temp_y < 1)
                temp_y = 1;
            
            if(temp_x >= scene->rows - 1)
                temp_x = scene->rows - 2;
            if(temp_y >= scene->cols - 1)
                temp_y = scene->cols - 2;
            
            if(scene->map[temp_x][temp_y] == '1' || scene->map[temp_x][temp_y] == 'X'){
                if(scene->map[temp_x][temp_y] == 'X')
                    kill_enemy(data, temp_x, temp_y);
                scene->map[temp_x][temp_y] = 'B';
            }
        }
    }
   render_player_view(*data, 0);
}

void explode_bombs(t_data *data)
{
    t_player *player = data->player;
    int i = player->max_bombs - player->bombs - 1;

    while(i < player->max_bombs)
    {
        if(i < 0)
            return;
        if(player->allbombs[i]->timer != -1 && player->allbombs[i]->exploded == 0){
            printf("bomb %d exploding in: %d\n",i, player->allbombs[i]->timer);
            if(player->allbombs[i]->timer > 0)
                player->allbombs[i]->timer--;
            else if(player->allbombs[i]->timer == 0)
                explode_bomb(data, i);
        }
        i++;
    }
}