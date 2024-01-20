/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:44:49 by escura            #+#    #+#             */
/*   Updated: 2024/01/20 13:47:16 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include <stdbool.h>

bool dfs(char **map, int x, int y, bool **visited, int rows, int cols) {
    if (x < 0 || y < 0 || x >= rows || y >= cols || visited[x][y] || map[x][y] == '1') {
        return false;
    }

    if (map[x][y] == 'E') {
        return true;
    }

    visited[x][y] = true;

    return dfs(map, x - 1, y, visited, rows, cols) || dfs(map, x + 1, y, visited, rows, cols) ||
           dfs(map, x, y - 1, visited, rows, cols) || dfs(map, x, y + 1, visited, rows, cols);
}

void convert_map(char *map_str, char ***map, int *rows, int *cols) {
    *rows = 1;
    *cols = 0;

    for (int i = 0; map_str[i] != '\0'; i++) {
        if (map_str[i] == '\n') {
            (*rows)++;
        } else if (*rows == 1) {
            (*cols)++;
        }
    }

    *map = malloc(*rows * sizeof(char *));
    for (int i = 0; i < *rows; i++) {
        (*map)[i] = malloc(*cols * sizeof(char));
    }

    int row = 0, col = 0;
    for (int i = 0; map_str[i] != '\0'; i++) {
        if (map_str[i] == '\n') {
            row++;
            col = 0;
        } else {
            (*map)[row][col] = map_str[i];
            col++;
        }
    }
}

int is_possible(char *map_str) {
    int rows, cols;
    char **map;
    convert_map(map_str, &map, &rows, &cols);

    bool **visited = malloc(rows * sizeof(bool *));
    for (int i = 0; i < rows; i++) {
        visited[i] = ft_calloc(cols, sizeof(bool));
    }

    int px, py;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (map[i][j] == 'P') {
                px = i;
                py = j;
                break;
            }
        }
    }

    int result = dfs(map, px, py, visited, rows, cols) ? 1 : 0;

    for (int i = 0; i < rows; i++) {
        free(map[i]);
        free(visited[i]);
    }
    free(map);
    free(visited);

    return result;
}
