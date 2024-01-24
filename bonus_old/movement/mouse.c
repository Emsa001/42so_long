/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:50:15 by escura            #+#    #+#             */
/*   Updated: 2024/01/24 14:17:07 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus_old.h"

int	mouse_hook(int button, int x, int y, t_data *data)
{
	printf("You've pressed: %d\n", button);
	printf("Mouse position: %d, %d\n", x, y);
	return (0);
}
