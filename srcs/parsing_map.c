/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:35:48 by thpham-v          #+#    #+#             */
/*   Updated: 2022/04/05 03:51:37 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_map(t_var *var)
{
	int	x;
	int	y;
	int	count;
	
	count = 0;
	x = 0;
	while (var->map[x])
	{
		y = 0;
		while (var->map[x][y])
		{
			if (var->map[x][y] == 'N' || var->map[x][y] == 'S' || var->map[x][y] == 'E' || var->map[x][y] == 'W')
			{
				var->pos_x = x;
				var->pos_y = y;
				var->player_dir = var->map[x][y];
				var->map[x][y] = '0';
				count++;
			}
			if (var->map[x][y] == '1' || var->map[x][y] == '0' || var->map[x][y] == 'N' || var->map[x][y] == ' ' ||
				var->map[x][y] == 'S' || var->map[x][y] == 'E' || var->map[x][y] == 'W')
				y++;
			else
				return (-1);
		}
		x++;
	}
	if (count > 1)				// fonction gestion de toute les erreurs map a faire
	{
		printf("Incorrect nbr joueur\n");
		return (-2);
	}
	return (0);
}

int		check_arround(t_var *var, int x, int y)
{
	if (var->map[x][y - 2] != '0' && var->map[x][y - 2] != '1')
		return (0);
	if (var->map[x][y + 2] != '0' && var->map[x][y + 2] != '1')
		return (0);
	if (var->map[x - 1][y] != '0' && var->map[x - 1][y] != '1')
		return (0);
	if (var->map[x + 1][y] != '0' && var->map[x + 1][y] != '1')
		return (0);
	return (1);
}

int	parsing_map(t_var *var)
{
	int x;
	int y;
	
	if (error_map(var) != 0)
		return (-1);
	x = 0;
	while (var->map[x])
	{
		y = 0;
		while (var->map[x][y])
		{
			if (var->map[x][y] == '0')
				if (!check_arround(var, x, y))
				{
					printf("The map is not closed\n");
					return (-1);
				}
			y++;
		}
		x++;
	}
	return (0);
}