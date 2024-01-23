/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:59:08 by escura            #+#    #+#             */
/*   Updated: 2024/01/23 01:47:04 by escura           ###   ########.fr       */
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
		ft_printf("Invalid map\n");
		free(map);
		exit(1);
	}
}

static void	check_for_border_and_size(t_readvars *r_vars)
{
	char	l1;
	char	l2;

	if (r_vars->line != NULL)
	{
		if (ft_strlen(r_vars->line) == 1)
			ft_error("Invalid map");
		l1 = r_vars->line[0];
		l2 = r_vars->line[r_vars->length - 1];
		if(l2 == '\n')
			l2 = r_vars->line[r_vars->length - 2];
		printf("line: |%s|\n", r_vars->line);
		if (ft_strlen(r_vars->line) != r_vars->length)
			r_vars->errors++;
		else if (l1 != '1' || l2 != '1')
			r_vars->errors++;
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
		check_for_border_and_size(r_vars);
		r_vars->line = get_next_line(fd);
	}
	free(r_vars->line);
	if (r_vars->errors > 0)
		ft_error("Invalid map");
	count_data(r_vars->map);
	temp = r_vars->map;
	free(r_vars);
	return (temp);
}
