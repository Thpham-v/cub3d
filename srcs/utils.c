/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 06:17:08 by thpham-v          #+#    #+#             */
/*   Updated: 2022/04/25 07:19:37 by thpham-v         ###   ########.fr       */
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
		if (*str != ' ')
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

int	ft_exit(t_var *var)
{
	if (var->map)
		ft_free_map(var);
	if (var->line)
		free(var->line);
	free(var->temp);
	if (var->no)
		free(var->no);
	if (var->so)
		free(var->so);
	if (var->we)
		free(var->we);
	if (var->ea)
		free(var->ea);
	exit(0);
}

void	ft_error(t_var *var, char *error_msg)
{
	ft_putstr("Error\n");
	ft_putstr(error_msg);
	ft_exit(var);
}
