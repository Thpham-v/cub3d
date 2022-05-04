/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:35:48 by thpham-v          #+#    #+#             */
/*   Updated: 2022/05/04 02:29:43 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_bis(t_var *var)
{
	if (var->map[var->x][var->y] == '1'
		|| var->map[var->x][var->y] == '0'
			|| var->map[var->x][var->y] == 'N'
				|| var->map[var->x][var->y] == 'S'
					|| var->map[var->x][var->y] == 'E'
						|| var->map[var->x][var->y] == 'W'
							|| var->map[var->x][var->y] == ' ')
		var->y++;
	else
		return (-1);
	return (0);
}

void	check_y(t_var *var)
{
	if (var->map[var->x][var->y] == 'N'
		|| var->map[var->x][var->y] == 'S'
			|| var->map[var->x][var->y] == 'E'
				|| var->map[var->x][var->y] == 'W')
	{
		var->player_dir = var->map[var->x][var->y];
		var->pos_x = var->x;
		var->pos_y = var->y;
		var->map[var->x][var->y] = '0';
		var->count++;
	}
}

int	error_map(t_var *var)
{
	while (var->map[var->x])
	{
		var->y = 0;
		if (var->map[var->x][0] == ' ')
			while (var->map[var->x][var->y] == ' ')
				var->y++;
		while (var->map[var->x][var->y])
		{
			check_y(var);
			if (error_bis(var) != 0)
				return (-1);
		}
		var->x++;
	}
	if (var->count != 1)
		return (-2);
	return (0);
}

void	parsing_map(t_var *var)
{
	int	x;
	int	y;

	if (error_map(var) != 0)
		ft_error(var, "Error in map\n");
	x = 0;
	while (var->map[x])
	{
		y = 0;
		while (var->map[x][y])
		{
			if (var->map[x][y] == '0')
				if (!check_arround(var, x, y))
					ft_error(var, "The map is not closed\n");
			y++;
		}
		x++;
	}
}

void	parsing_file(char *file, t_var *var)
{
	int		ret;
	int		is_map;

	ret = 1;
	is_map = 0;
	open_file(file, var);
	while (ret == 1)
	{
		ret = get_next_line(var->fd, &var->line, &var->temp, 1);
		if (!is_map_params(var))
		{
			get_map_params(var->line, var);
			var->what_line++;
		}
		else if (!is_empty(var->line))
			is_map++;
		else if (is_empty(var->line) && is_map == 0)
			var->what_line++;
		free(var->line);
		var->line = NULL;
	}
	close(var->fd);
	if (!is_map_params(var))
		exit(1);
}
