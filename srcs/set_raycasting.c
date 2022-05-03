/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_raycasting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 06:07:28 by htizi             #+#    #+#             */
/*   Updated: 2022/04/27 08:52:16 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_move(t_var *var)
{
	var->move.forward = 0;
	var->move.back = 0;
	var->move.left = 0;
	var->move.right = 0;
	var->move.rotate_left = 0;
	var->move.rotate_right = 0;
	var->move.move_speed = 0.1;
	var->move.rotation_speed = 0.1;
}

void	init_ray_var(t_var *var)
{
	if (var->player_dir == 'N')
	{
		var->ray.dirx = -1;
		var->ray.plany = 0.66;
	}
	if (var->player_dir == 'S')
	{
		var->ray.dirx = 1;
		var->ray.plany = -0.66;
	}
	if (var->player_dir == 'E')
	{
		var->ray.diry = 1;
		var->ray.planx = 0.66;
	}
	if (var->player_dir == 'W')
	{
		var->ray.diry = -1;
		var->ray.planx = -0.66;
	}
	var->ray.posx = (double)var->pos_x + 0.5;
	var->ray.posy = (double)var->pos_y + 0.5;
}

void	init_raycasting(t_var *var)
{
	init_move(var);
	init_ray_var(var);
}
