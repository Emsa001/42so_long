/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:46:56 by escura            #+#    #+#             */
/*   Updated: 2024/01/20 21:54:23 by escura           ###   ########.fr       */
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

typedef struct s_textures
{
	char		*wall;
	char		*floor;
	char		*exit;
	char		*player[3];
	char		*enemy[2];
	char		*collectible[3];
}				t_textures;

typedef struct s_scene
{
	char		**map;
	int			cols;
	int			rows;

	int			exit_x;
	int			exit_y;
	int			collectibles;

	int			block_size;
	int			**rerender;
}				t_scene;

typedef struct s_player
{
	int			x;
	int			y;

	int			moves;
	int			alive;
	int			attack;
	char		*texture;
}				t_player;

typedef struct s_enemy
{
	int			x;
	int			y;

	int			prev_x;
	int			prev_y;

	int			alive;
	int			direction;

	char		*texture;
}				t_enemy;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;

	t_scene		*scene;
	t_player	*player;

	t_enemy		*enemy;
	t_textures	*textures;

	int			game_over;

	int			*img;
	int			text_shown;
}				t_data;

int				key_hook(int keycode, t_data *data);
int				mouse_hook(int button, int x, int y, t_data *vars);
int				create_trgb(unsigned char t, unsigned char r, unsigned char g,
					unsigned char b);
int				random_color(void);
void			render_scene(t_data *data);
void			render_static(t_data data);
void			render_moves(t_data data);
void			load_image(char *path, t_data data, int x, int y);

char			*ft_strtok(char *str, char *delim);
void			set_real_position(t_data *data, int *x_pos, int *y_pos, char c);
void			update_map(t_data data);
void			victory(t_data *data);
void			show_text(t_data *data, char *message);
void			init_data(t_data *data, char *map);
int				is_possible(char *map_str);
int				count(char *map, char c);

char			*read_map(char *path);
void			convert_map(char *map_str, char ***map, int *rows, int *cols);
void			print_map(const t_scene *scene);
void			free_data(t_data *data);
void			render_dynamic(t_data data);
void			re_render(t_data *data);

int				check_if_safe(t_data *data, int x, int y);
int				check_objectives(t_data *data, int x, int y);

int				enemy_move(t_data *data);
void			kill_player(t_data *data);
void			init_enemy(t_data *data);
void			kill_enemy(t_data *data);
int				find_player(const t_scene *scene);

#endif
