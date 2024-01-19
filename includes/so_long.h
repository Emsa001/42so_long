/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:46:56 by escura            #+#    #+#             */
/*   Updated: 2024/01/19 18:33:19 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;

	char	*map;
	int		rerender;

	int		mapRows;
	int		mapCols;
	int		exit_x;
	int		exit_y;
	int		block_size;
	int		player_direction;
	int		player_x;
	int		player_y;

	int		*img;

	int		moves_count;
	int		text_shown;

	double	size;
}			t_data;

typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}			t_rect;

int			key_hook(int keycode, t_data *vars);
int			mouse_hook(int button, int x, int y, t_data *vars);
int			create_trgb(unsigned char t, unsigned char r, unsigned char g,
				unsigned char b);
int			random_color(void);
int			render_rect(t_data data, t_rect rect);
void		render_scene(t_data *data);
void		render_static(t_data data);
void		render_moves(t_data data);
void		load_image(char *path, t_data data, int x, int y);
void		set_real_positions(t_data *data);

int			map_get_rows(char *map);
int			map_get_cols(char *map);

char		*ft_strtok(char *str, char *delim);
int			find_position(char *map, char c);
void		update_map(t_data data);
void		victory(t_data *data);
void		show_text(t_data *data, char *message);
void		init_data(t_data *data, char *map);
int			is_possible(char *map_str);
int			count(char *map, char c);

char		*read_map(char *path);

#endif

// https://www.youtube.com/watch?v=10P59aOgi68