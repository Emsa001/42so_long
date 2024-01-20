/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:53:48 by escura            #+#    #+#             */
/*   Updated: 2024/01/20 18:12:04 by escura           ###   ########.fr       */
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

void free_data(t_data *data)
{
    
    free_scene(data->scene);
    free(data->player);
    free_rerender(data->scene->rerender);
    if (data->win){
        mlx_destroy_window(data->mlx, data->win);
        exit(0);
    }
}