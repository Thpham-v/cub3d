/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 09:59:00 by htizi             #+#    #+#             */
/*   Updated: 2022/04/26 13:49:04 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_var *var)
{
	double	olddirx;
	double	oldplanex;

	if (var->move.rotate_left == 1)
	{
		olddirx = var->ray.dirx;
		var->ray.dirx = var->ray.dirx * cos(var->move.rotation_speed / 2)
			- var->ray.diry * sin(var->move.rotation_speed / 2);
		var->ray.diry = olddirx * sin(var->move.rotation_speed / 2)
			+ var->ray.diry * cos(var->move.rotation_speed / 2);
		oldplanex = var->ray.planx;
		var->ray.planx = var->ray.planx * cos(var->move.rotation_speed / 2)
			- var->ray.plany * sin(var->move.rotation_speed / 2);
		var->ray.plany = oldplanex * sin(var->move.rotation_speed / 2)
			+ var->ray.plany * cos(var->move.rotation_speed / 2);
	}
}

void	rotate_right(t_var *var)
{
	double	olddirx;
	double	oldplanex;

	if (var->move.rotate_right == 1)
	{
		olddirx = var->ray.dirx;
		var->ray.dirx = var->ray.dirx * cos(-var->move.rotation_speed / 2)
			- var->ray.diry * sin(-var->move.rotation_speed / 2);
		var->ray.diry = olddirx * sin(-var->move.rotation_speed / 2)
			+ var->ray.diry * cos(-var->move.rotation_speed / 2);
		oldplanex = var->ray.planx;
		var->ray.planx = var->ray.planx * cos(-var->move.rotation_speed / 2)
			- var->ray.plany * sin(-var->move.rotation_speed / 2);
		var->ray.plany = oldplanex * sin(-var->move.rotation_speed / 2)
			+ var->ray.plany * cos(-var->move.rotation_speed / 2);
	}
}
