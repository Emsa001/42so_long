/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:53:48 by escura            #+#    #+#             */
/*   Updated: 2024/01/21 23:34:07 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void  free_scene(t_scene *scene)
{
    int i;

    i = 0;
    while (i < scene->rows)
        free(scene->map[i++]);
    free(scene->map);
    free(scene->map_string);
    free(scene);
}

void free_rerender(int **rerender)
{
    int i;

    i = 0;
    if(!rerender)
        return ;
    while (rerender[i])
        free(rerender[i++]);
    free(rerender);
}

void free_enemies(t_data *data)
{
    t_enemy **enemy = data->enemy;
    const t_scene *scene = data->scene;

    int i;

    i = 0;
    int enemies = count(scene->map_string, 'X');
    while (i < enemies)
        free(enemy[i++]);
    free(enemy);
}

int free_data(t_data *data)
{
    free(data->player);
    free_rerender(data->scene->rerender);
    free_enemies(data);
    free_scene(data->scene);

    if (data->win){
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }

    return 0;
}