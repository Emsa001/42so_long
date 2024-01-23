/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:23:59 by escura            #+#    #+#             */
/*   Updated: 2024/01/23 01:26:05 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_vars
{
	int		rows;
	int		cols;

	char	**map;
	int		**visited;

	int		px;
	int		py;
}			t_vars;

typedef struct s_readvars
{
	char	*line;
	char	*map;
	char	*temp;
	int		length;
	int		errors;
}			t_readvars;

int			is_possible(t_vars *vars);