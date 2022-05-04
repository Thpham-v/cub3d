/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 06:17:08 by thpham-v          #+#    #+#             */
/*   Updated: 2022/05/04 02:57:25 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_params(t_var *var)
{
	if (var->no == NULL || var->so == NULL
		|| var->we == NULL || var->ea == NULL)
		return (0);
	if (var->f == -1 || var->c == -1)
		return (0);
	return (1);
}

int	is_empty(char *str)
{
	while (*str)
	{
		if (*str != ' ' || *str != '\t')
			return (0);
		str++;
	}
	return (1);
}

int	skip_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

void	ft_error(t_var *var, char *error_msg)
{
	ft_putstr("Error\n");
	ft_putstr(error_msg);
	ft_exit(var);
}

int	check_arround(t_var *var, int x, int y)
{
	if (var->map[x][y - 1] != '0' && var->map[x][y - 1] != '1')
		return (0);
	if (var->map[x][y + 1] != '0' && var->map[x][y + 1] != '1')
		return (0);
	if (var->map[x - 1][y] != '1' && ft_strlen(var->map[x - 1]) <= y)
		return (0);
	if (var->map[x - 1][y] != '0' && var->map[x - 1][y] != '1')
		return (0);
	if (!var->map[x + 1] || var->map[x + 1][y] != '1' && ft_strlen(var->map[x + 1]) <= y)
		return (0);
	if (!var->map[x + 1] || var->map[x + 1][y] != '0' && var->map[x + 1][y] != '1')
		return (0);
	return (1);
}

