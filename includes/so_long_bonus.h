/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:46:56 by escura            #+#    #+#             */
/*   Updated: 2024/01/22 15:03:06 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

typedef struct s_textures
{
	char		*wall;
	char		*floor;
	char		*exit[2];
	char		*player[12];
	char		*enemy[8];
	char		*collectible[2];
	char		*explosion[5];
	char 		*message[2];
}				t_textures;

typedef struct s_scene
{
	char		**map;
	char		*map_string;
	int			cols;
	int			rows;

	int			exit_texture;
	int			collectibles;
	int			boom_animation;

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
	int			direction;
	int			texture;
	int			bombs;
}				t_player;

typedef struct s_enemy
{
	int			x;
	int			y;

	int			prev_x;
	int			prev_y;

	int			alive;
	int			direction;

	int			texture;
}				t_enemy;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;

	t_scene		*scene;
	t_player	*player;

	t_enemy		**enemy;
	t_textures	*textures;

	int			game_over;
	int			frame_update;

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
int				free_data(t_data *data);
void			render_dynamic(t_data data);
void			re_render(t_data *data);

int				check_if_safe(t_data *data, int x, int y);
int				check_objectives(t_data *data, int x, int y);

int				enemy_move(t_data *data, t_enemy *enemy);
void			kill_player(t_data *data);
void			init_enemy(t_data *data);
void			kill_enemy(t_data *data, int x, int y);
int				find_player(const t_scene *scene);
void			boom(t_data *data);
void 			render_enemy(t_data *data, t_enemy *enemy);


#endif
