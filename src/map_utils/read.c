/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:59:08 by escura            #+#    #+#             */
/*   Updated: 2024/01/29 12:18:47 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include "./alias.h"

static void	strjoin_error(char *map, char *line)
{
	free(map);
	free(line);
	ft_error("Failed to allocate memory for map");
}

static void	count_data(char *map)
{
	if (count(map, 'P') != 1 || count(map, 'E') != 1 || count(map, 'C') < 1)
	{
		ft_printf("Map Error\n");
		free(map);
		exit(1);
	}
}

void	check_and_init(int fd, t_readvars *r_vars)
{
	if (r_vars == NULL)
		ft_error("Failed to allocate memory for temp");
	if (fd == -1)
		ft_error("Failed to open map file");
	r_vars->errors = 0;
	r_vars->line = get_next_line(fd);
	r_vars->map = ft_calloc(1, sizeof(char));
	if (r_vars->map == NULL)
		ft_error("Failed to allocate memory for map");
}

char	*read_map(char *path)
{
	const int	fd = open(path, O_RDONLY);
	t_readvars	*r_vars;
	char		*temp;

	r_vars = ft_calloc(1, sizeof(t_readvars));
	check_and_init(fd, r_vars);
	while (r_vars->line != NULL)
	{
		r_vars->temp = r_vars->map;
		r_vars->length = ft_strlen(r_vars->line);
		r_vars->map = ft_strjoin(r_vars->map, r_vars->line);
		if (r_vars->map == NULL)
			strjoin_error(r_vars->temp, r_vars->line);
		free(r_vars->temp);
		free(r_vars->line);
		r_vars->line = get_next_line(fd);
	}
	free(r_vars->line);
	if (r_vars->errors > 0)
		ft_error("Map Error");
	count_data(r_vars->map);
	temp = r_vars->map;
	free(r_vars);
	return (temp);
}
