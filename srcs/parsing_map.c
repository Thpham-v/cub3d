/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:35:48 by thpham-v          #+#    #+#             */
/*   Updated: 2022/03/23 03:37:04 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_map(char **map)
{
	int	i;
	int	j;
	int	pos_player;
	
	i = 0;
	pos_player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
				pos_player++;
			if (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == ' ' ||
				map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
				j++;
			else
				return (-1);
		}
		i++;
	}
	if (pos_player > 1)
	{
		printf("Incorrect nbr joueur\n");
		return (-2);
	}
	return (0);
}

/*int	open_or_close(char **map)
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
}*/

int	parsing_map(t_var *var)
{
	if (error_map(var->map) != 0)
		return (-1);
	//if (open_or_close(var->map) == -2)
		//return (-2);
	return (0);
}