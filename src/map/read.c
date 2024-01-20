/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:59:08 by escura            #+#    #+#             */
/*   Updated: 2024/01/20 17:53:36 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int count(char *map, char c)
{
	int i = 0;
	int count = 0;
	while(map[i] != '\0')
	{
		if(map[i] == c)
			count++;
		i++;
	}
	return count;
}

char *read_map(char *path)
{
    int fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        printf("Failed to open file\n");
        exit(1);
    }

    char *line = get_next_line(fd);
    char *map = ft_calloc(1, sizeof(char)); 
    char *temp;
    while(line != NULL)
    {
        temp = map; 
        map = ft_strjoin(map, line); 
        free(temp);  
        free(line);
        line = get_next_line(fd);
    }
    free(line);

    if(count(map, 'P') != 1 || count(map, 'E') != 1 || count(map, 'C') < 1)
    {
        printf("Invalid map\n");
        free(map);
        exit(1);
    }

    return map;
}