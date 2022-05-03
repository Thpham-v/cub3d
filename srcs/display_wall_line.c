/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_wall_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:10:35 by htizi             #+#    #+#             */
/*   Updated: 2022/04/26 15:33:47 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_texel_dir(t_var *var)
{
	if (var->ray.side == 0 && var->ray.raydirx < 0)
		var->texel.dir = 0;
	if (var->ray.side == 0 && var->ray.raydirx >= 0)
		var->texel.dir = 1;
	if (var->ray.side == 1 && var->ray.raydiry < 0)
		var->texel.dir = 2;
	if (var->ray.side == 1 && var->ray.raydiry >= 0)
		var->texel.dir = 3;
}

void	set_texel_wallx(t_var *var)
{
	if (var->ray.side == 0)
		var->texel.wallx = var->ray.posy + var->ray.perpwalldist
			* var->ray.raydiry;
	else
		var->texel.wallx = var->ray.posx + var->ray.perpwalldist
			* var->ray.raydirx;
	var->texel.wallx -= floor((var->texel.wallx));
}

void	set_texel_texx(t_var *var)
{
		var->texel.texx = (int)(var->texel.wallx
			* (double)var->textures[var->texel.dir].width);
	if (var->ray.side == 0 && var->ray.raydirx > 0)
		var->texel.texx = var->textures[var->texel.dir].width
			- var->texel.texx - 1;
	if (var->ray.side == 1 && var->ray.raydiry < 0)
		var->texel.texx = var->textures[var->texel.dir].width
			- var->texel.texx - 1;
}

void	set_texel_var(t_var *var)
{
	set_texel_wallx(var);
	set_texel_texx(var);
	var->texel.step = 1.0 * var->textures[0].height / var->ray.lineheight;
	var->texel.texpos = (var->ray.drawstart - SCREEN_Y / 2
			+ var->ray.lineheight / 2) * var->texel.step;
}

void	display_wall_line(t_var *var, int x, int y)
{
	int	color;

	set_texel_var(var);
	set_texel_dir(var);
	while (y <= var->ray.drawend)
	{
		var->texel.texy = (int)var->texel.texpos
			&(var->textures[var->texel.dir].height - 1);
		var->texel.texpos += var->texel.step;
		if (y < SCREEN_Y && x < SCREEN_X)
		{
			color = var->textures[var->texel.dir].addr[var->texel.texy
				* var->textures[var->texel.dir].line_len / 4 + var->texel.texx];
			var->mlx.addr[y * var->mlx.line_len / 4 + x] = color;
		}
		y++;
	}
}
