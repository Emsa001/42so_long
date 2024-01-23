/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:44:49 by escura            #+#    #+#             */
/*   Updated: 2024/01/23 01:29:32 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "./alias.h"

int	check_if_correct(char *map_str)
{
	t_vars	*vars;

	vars = ft_calloc(1, sizeof(t_vars));
	if (vars == NULL)
		return (0);
	convert_map(map_str, &vars->map, &vars->rows, &vars->cols);
	if (is_possible(vars) == 0)
		return (0);
	return (1);
}

int	count(char *map, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i] != '\0')
	{
		if (map[i] == c)
			count++;
		i++;
	}
	return (count);
}
