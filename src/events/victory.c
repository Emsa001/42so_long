/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   victory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:54:12 by escura            #+#    #+#             */
/*   Updated: 2024/01/22 22:54:17 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	victory(t_data *data)
{
	announce(data, "Victory!");
	show_text(data, "Press ESC to exit");
	data->game_over = 1;
}
