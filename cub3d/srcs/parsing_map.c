/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:35:48 by thpham-v          #+#    #+#             */
/*   Updated: 2022/03/18 05:12:17 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == 'N' || line[i] == ' ' ||
			line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			i++;
		else
			return (-1);
	}
	return (0);
}

int	open_or_close(int len, char **map)
{
	int j;
	
	j = 0;
	while (map[0][j]) // premier ligne de la map
	{
		if (map[0][j] != '1' && map[0][j] != ' ')
		{
			printf("Map ouverte 1\n");
			return (-2);
		}
		j++;
	}
	j = 0;
	while (map[len][j]) // derniere ligne de la map
	{
		if (map[len][j] != '1' && map[len][j] != ' ')
		{
			printf("Map ouverte 2\n");
			return (-2);
		}
		j++;
	}
	len--;
	while (len != 0) // milieu de map
	{
		j = 0;
		while (map[len][j])
		{
			if (map[len][0] != '1')
			{
			printf("Map ouverte 3\n");
			return (-2);
			}
			j++;
		}
		if (map[len][j - 1] != '1')
		{
			printf("Map ouverte 4\n");
			return (-2);
		}
		len--;
	}
	return (0);
}

int	parsing_map(char **map)
{
	int	i;
	
	i = 0;
	while (map[i])
	{
		if (error_map(map[i]) == -1)
			return (-1);
		i++;
	}
	if (open_or_close(i - 1, map) == -2)
		return (-2);
	return (0);
}