/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:38:25 by escura            #+#    #+#             */
/*   Updated: 2024/01/18 16:38:29 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*ft_strtok(char *str, char *delim)
{
	static char	*next;
	char		*ret;

	int i, j;
	if (str != NULL)
		next = str;
	if (next == NULL)
		return (NULL);
	i = 0;
	while (next[i] != '\0')
	{
		j = 0;
		while (delim[j] != '\0')
		{
			if (next[i] == delim[j])
			{
				next[i] = '\0';
				ret = next;
				next = &next[i + 1];
				return (ret);
			}
			j++;
		}
		i++;
	}
	ret = next;
	next = NULL;
	return (ret);
}
