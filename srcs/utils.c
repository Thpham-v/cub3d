/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 06:17:08 by thpham-v          #+#    #+#             */
/*   Updated: 2022/04/22 09:34:31 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_exit(t_var *var)
{
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
}