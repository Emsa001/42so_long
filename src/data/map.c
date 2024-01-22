/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:14:29 by escura            #+#    #+#             */
/*   Updated: 2024/01/22 19:32:41 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"


void set_pixel_position(t_data *data, int *x, int *y, char c)
{
	const t_scene *scene = data->scene;
	
	for (int i = 0; i < scene->player_map_rows; i++) {
        for (int j = 0; j < scene->player_map_cols; j++) {
            if(scene->player_map[i][j] == c){
				*x = j * scene->block_size;
				*y = i * scene->block_size;
				return ;
			}
        }
    }
}

void set_real_position(t_data *data, int *x_pos, int *y_pos, char c)
{
	const t_scene *scene = data->scene;

	int x = 0;
	int y = 0;
	while(scene->map[x][y] != c)
	{
		y++;
		if(y == scene->cols)
		{
			y = 0;
			x++;
		}
	}

	*x_pos = x;
	*y_pos = y;
}

void print_player_map(const t_scene *scene)
{
	printf("\n");
    for (int i = 0; i < scene->player_map_rows; i++) {
        for (int j = 0; j < scene->player_map_cols; j++) {
            printf("%c ", scene->player_map[i][j]);
        }
        printf("\n");
    }
}

void print_full_map(const t_scene *scene)
{
	printf("\n");
	for(int i = 0; i < scene->rows; i++)
    {
        for(int j = 0; j < scene->cols; j++)
            printf("%c", scene->map[i][j]);
        printf("\n");
    }
	printf("\n");
}

void free_player_map(t_scene *scene)
{
	for (int i = 0; i < scene->player_map_rows; i++) {
		free(scene->player_map[i]);
	}
	free(scene->player_map);
}

void set_player_map(t_data *data)
{
	int player_x = data->player->x;
	int player_y = data->player->y;
	t_scene *scene = data->scene;


	int rows = scene->player_map_rows;
    int cols = scene->player_map_cols;

	int start_x = 0;
	int start_y = 0;
	int end_x = rows;
	int end_y = cols;

	if(rows >= 20){
		start_x = player_x - 10 >= 0 ? player_x - 10 : 0;
		if(player_x > scene->rows - 10)
			start_x = scene->rows - 20;
		end_x = start_x + 20 < scene->rows ? start_x + 20 : scene->rows;
		rows = 20;
	}
	if(cols >= 20){
		start_y = player_y - 10 >= 0 ? player_y - 10 : 0;
		if(player_y > scene->cols - 10)
			start_y = scene->cols - 20;
		end_y = start_y + 20 < scene->cols ? start_y + 20 : scene->cols;
		cols = 20;
	}

	if(scene->player_map != NULL)
		free_player_map(scene);

	scene->player_map = malloc(rows * sizeof(char *));
	for (int i = 0; i < rows; i++) {
		scene->player_map[i] = malloc(cols * sizeof(char));
		for (int j = 0; j < cols; j++) {
			int temp_x = i + start_x;
			int temp_y = j + start_y;
			if(cols <= 20)
				scene->player_map[i][j] = scene->map[temp_x][temp_y];
			else{
				if (temp_x < end_x && temp_y < end_y) {
					scene->player_map[i][j] = scene->map[temp_x][temp_y];
				} else {
					scene->player_map[i][j] = ' ';
				}
			}
		}
	}	
}
