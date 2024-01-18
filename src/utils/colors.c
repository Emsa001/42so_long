/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:34:41 by escura            #+#    #+#             */
/*   Updated: 2024/01/18 15:00:44 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	create_trgb(unsigned char t, unsigned char r, unsigned char g,
		unsigned char b)
{
	return (*(int *)(unsigned char[4]){b, g, r, t});
}

int random_color(){
	return (create_trgb(0, rand() % 255, rand() % 255, rand() % 255));
}