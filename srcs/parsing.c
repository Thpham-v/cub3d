/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:35:48 by thpham-v          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/04 01:09:08 by thpham-v         ###   ########.fr       */
=======
/*   Updated: 2022/04/26 10:54:13 by thpham-v         ###   ########.fr       */
>>>>>>> d96357da57388ef11cc1c08d06da79cbae459b40
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_bis(t_var *var)
{
<<<<<<< HEAD
=======
	if (var->map[var->x][0] == ' ')
	{
		while (var->map[var->x][var->y] == ' ')
			var->y++;
	}
>>>>>>> d96357da57388ef11cc1c08d06da79cbae459b40
	if (var->map[var->x][var->y] == '1'
		|| var->map[var->x][var->y] == '0'
			|| var->map[var->x][var->y] == 'N'
				|| var->map[var->x][var->y] == 'S'
					|| var->map[var->x][var->y] == 'E'
						|| var->map[var->x][var->y] == 'W')
<<<<<<< HEAD
			var->y++;
	else if (var->map[var->x][var->y] == ' ' || var->map[var->x][var->y] == '\t')
		ft_error(var, "Space are not autorized\n");
=======
		var->y++;
>>>>>>> d96357da57388ef11cc1c08d06da79cbae459b40
	else
		return (-1);
	return (0);
}

int	error_map(t_var *var)
{
	while (var->map[var->x])
	{
		var->y = 0;
<<<<<<< HEAD
		if (var->map[var->x][0] == ' ')
		while (var->map[var->x][var->y] == ' ')
			var->y++;
=======
>>>>>>> d96357da57388ef11cc1c08d06da79cbae459b40
		while (var->map[var->x][var->y])
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
			if (error_bis(var) != 0)
				return (-1);
		}
		var->x++;
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
<<<<<<< HEAD
	if (var->map[x - 1][y] != '1' && ft_strlen(var->map[x - 1]) <= y)
		return (0);
	if (var->map[x - 1][y] != '0' && var->map[x - 1][y] != '1')
		return (0);
	if (var->map[x + 1][y] != '1' && ft_strlen(var->map[x + 1]) <= y)
		return (0);
=======
	if (var->map[x - 1][y] != '0' && var->map[x - 1][y] != '1')
		return (0);
>>>>>>> d96357da57388ef11cc1c08d06da79cbae459b40
	if (var->map[x + 1][y] != '0' && var->map[x + 1][y] != '1')
		return (0);
	return (1);
}

void	parsing_map(t_var *var)
{
	int	x;
	int	y;

	if (error_map(var) != 0)
<<<<<<< HEAD
		ft_error(var, "Error in map\n");
=======
		ft_error(var, "Incorrect number of players\n");
>>>>>>> d96357da57388ef11cc1c08d06da79cbae459b40
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
<<<<<<< HEAD
	int		is_map;

	ret = 1;
	is_map = 0;
=======

	ret = 1;
>>>>>>> d96357da57388ef11cc1c08d06da79cbae459b40
	open_file(file, var);
	while (ret == 1)
	{
		ret = get_next_line(var->fd, &var->line, &var->temp, 1);
		if (!is_map_params(var))
		{
			get_map_params(var->line, var);
			var->what_line++;
		}
<<<<<<< HEAD
		else if (!is_empty(var->line))
			is_map++;
		else if (is_empty(var->line) && is_map == 0)
=======
		else if (is_empty(var->line) && var->nb_l == 0)
>>>>>>> d96357da57388ef11cc1c08d06da79cbae459b40
			var->what_line++;
		free(var->line);
		var->line = NULL;
	}
	close(var->fd);
	if (!is_map_params(var))
		exit(1);
}
