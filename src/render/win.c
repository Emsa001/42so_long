/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:09:01 by escura            #+#    #+#             */
/*   Updated: 2024/01/18 17:09:08 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void you_win(t_data *data)
{
    mlx_string_put(data->mlx, data->win, 100, 100, 0x00f59e0b, "You win!");
    mlx_string_put(data->mlx, data->win, 100, 120, 0x00f59e0b, "Press ESC to exit");
}