/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:46:56 by escura            #+#    #+#             */
/*   Updated: 2024/01/25 18:19:09 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/src/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_textures
{
	char		*wall;
	char		*floor;
	char		*empty;
	char		*exit[2];
	char		*enemy[4];
	char		*player[14];
	char		*bomb[5];
	char		*explosion[5];
	char		*collectible;
	char		*message[2];
}				t_textures;

typedef struct s_scene
{
	char		**map;
	char		**player_map;
	char		*map_string;
	int			cols;
	int			rows;
	int			player_map_cols;
	int			player_map_rows;
	char		*text;
	int			text_shown;
	int			boom_animation;

	int			enemies_alive;

	int			exit_texture;
	int			collectibles;

	int			block_size;
}				t_scene;

typedef struct s_bomb
{
	int			x;
	int			y;
	int			exploded;
	int			timer;
}				t_bomb;

typedef struct s_player
{
	int			x;
	int			y;

	int			prev_x;
	int			prev_y;

	int			alive;
	int			moves;
	int			direction;
	int			texture;
	int			texture_add;
	int			running;

	int			bombs;
	int			max_bombs;
	t_bomb		**allbombs;
}				t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;

	t_scene		*scene;
	t_player	*player;
	t_player	**enemy;

	t_textures	*textures;

	int			game_over;
	int			frame_update;

	int			*img;
	int			text_shown;
}				t_data;

int				key_hook(int keycode, t_data *data);
void			render_moves(t_data data);
void			load_image(char *path, t_data data, int x, int y);

void			set_real_position(t_data *data, int *x_pos, int *y_pos, char c);
void			victory(t_data *data);
void			show_text(t_data *data, char *message);
void			init_data(t_data *data, char *map);
int				check_if_correct(char *map_str);
int				count(char *map, char c);

char			*read_map(char *path);
void			convert_map(char *map_str, char ***map, int *rows, int *cols);
void			print_full_map(const t_scene *scene);
void			print_player_map(const t_scene *scene);
int				free_data(t_data *data);

int				check_if_safe(t_data *data, int x, int y);
int				check_objectives(t_data *data, int x, int y);

void			set_player_map(t_data *data);
void			render_player_view(t_data data, int i);
void			free_player_map(t_scene *scene);
void			animation_update(t_data data);
void			set_pixel_position(t_data *data, int *x, int *y, char c);
void			announce(t_data *data, char *message);

void			ft_error(char *msg);

void			spawn_enemies(t_data *data);
void			render_enemies(t_data *data);
void			render_enemy_2(t_data *data, t_player *enemy);
void			render_enemy(t_data *data, int x, int y);
int				move_enemy(t_data *data, t_player *enemy);
void			move_enemies(t_data *data);
void			kill_enemy(t_data *data, int x, int y);
void			kill_player(t_data *data);
void			init_bombs(t_data *data);
void			spawn_bomb(t_data *data, int x, int y);
void			explode_bombs(t_data *data);
int				rnd(int min, int max);
void			init_enemies(t_data *data);

#endif
