/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:35:48 by thpham-v          #+#    #+#             */
/*   Updated: 2022/04/25 07:45:28 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_bis(t_var *var)
{
	if (var->map[var->pos_x][0] == ' ')
	{
		while (var->map[var->pos_x][var->pos_y] == ' ')
			var->pos_y++;
	}
	if (var->map[var->pos_x][var->pos_y] == '1'
		|| var->map[var->pos_x][var->pos_y] == '0'
			|| var->map[var->pos_x][var->pos_y] == 'N'
				|| var->map[var->pos_x][var->pos_y] == 'S'
					|| var->map[var->pos_x][var->pos_y] == 'E'
						|| var->map[var->pos_x][var->pos_y] == 'W')
		var->pos_y++;
	else
		return (-1);
	return (0);
}

int	error_map(t_var *var)
{
	while (var->map[var->pos_x])
	{
		var->pos_y = 0;
		while (var->map[var->pos_x][var->pos_y])
		{
			if (var->map[var->pos_x][var->pos_y] == 'N'
				|| var->map[var->pos_x][var->pos_y] == 'S'
					|| var->map[var->pos_x][var->pos_y] == 'E'
						|| var->map[var->pos_x][var->pos_y] == 'W')
			{
				var->player_dir = var->map[var->pos_x][var->pos_y];
				var->map[var->pos_x][var->pos_y] = '0';
				var->count++;
			}
			if (error_bis(var) != 0)
				return (-1);
		}
		var->pos_x++;
	}
	if (var->count != 1)
		return (-2);
	return (0);
}

int	check_arround(t_var *var, int x, int y)
{
	if (var->map[x][y - 1] != '0' && var->map[x][y - 1] != '1')
		return (0);
	if (var->map[x][y + 1] != '0' && var->map[x][y + 1] != '1')
		return (0);
	if (var->map[x - 1][y] != '0' && var->map[x - 1][y] != '1')
		return (0);
	if (var->map[x + 1][y] != '0' && var->map[x + 1][y] != '1')
		return (0);
	return (1);
}

void	parsing_map(t_var *var)
{
	int	x;
	int	y;

	if (error_map(var) != 0)
		ft_error(var, "Incorrect number of players\n");
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

	ret = 1;
	open_file(file, var);
	while (ret == 1)
	{
		ret = get_next_line(var->fd, &var->line, &var->temp, 1);
		if (!is_map_params(var))
		{
			get_map_params(var->line, var);
			var->what_line++;
		}
		else if (is_empty(var->line) && var->nb_l == 0)
			var->what_line++;
		free(var->line);
		var->line = NULL;
	}
	close(var->fd);
	if (!is_map_params(var))
		exit(1);
}
