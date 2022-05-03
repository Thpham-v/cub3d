/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 07:04:21 by htizi             #+#    #+#             */
/*   Updated: 2022/04/26 13:52:41 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_delta(t_var *var)
{
	if (var->ray.raydiry == 0)
		var->ray.deltadistx = 0;
	else if (var->ray.raydirx == 0)
		var->ray.deltadistx = 1;
	else
		var->ray.deltadistx = sqrt(1 + (var->ray.raydiry * var->ray.raydiry)
				/ (var->ray.raydirx * var->ray.raydirx));
	if (var->ray.raydirx == 0)
		var->ray.deltadisty = 0;
	else if (var->ray.raydiry == 0)
		var->ray.deltadisty = 1;
	else
		var->ray.deltadisty = sqrt(1 + (var->ray.raydirx * var->ray.raydirx)
				/ (var->ray.raydiry * var->ray.raydiry));
}

void	set_step_sidedist(t_var *var)
{
	if (var->ray.raydirx < 0)
	{
		var->ray.stepx = -1;
		var->ray.sidedistx = (var->ray.posx - var->ray.mapx)
			* var->ray.deltadistx;
	}
	else
	{
		var->ray.stepx = 1;
		var->ray.sidedistx = (var->ray.mapx + 1.0 - var->ray.posx)
			* var->ray.deltadistx;
	}
	if (var->ray.raydiry < 0)
	{
		var->ray.stepy = -1;
		var->ray.sidedisty = (var->ray.posy - var->ray.mapy)
			* var->ray.deltadisty;
	}
	else
	{
		var->ray.stepy = 1;
		var->ray.sidedisty = (var->ray.mapy + 1.0 - var->ray.posy)
			* var->ray.deltadisty;
	}
}

void	set_ray(t_var *var, int x)
{
	var->ray.camerax = 2 * x / (double)SCREEN_X - 1;
	var->ray.raydirx = var->ray.dirx + var->ray.planx * var->ray.camerax;
	var->ray.raydiry = var->ray.diry + var->ray.plany * var->ray.camerax;
	var->ray.mapx = (int)var->ray.posx;
	var->ray.mapy = (int)var->ray.posy;
	set_delta(var);
	var->ray.hit = 0;
	set_step_sidedist(var);
}
