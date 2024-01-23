/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:23:59 by escura            #+#    #+#             */
/*   Updated: 2024/01/23 16:11:03 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_vars
{
	int		rows;
	int		cols;

	char	**map;
	int		**visited;
	char	static_tiles[3];
	char	to_find;

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

int			count_converted(t_vars *vars, char to_find);
int			is_possible(t_vars *vars);
void		clear_visited(t_vars *vars);
int			free_memory(t_vars *vars);
int			check_if_can_walk(t_vars *vars, int x, int y);