/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_and_draw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 09:18:13 by htizi             #+#    #+#             */
/*   Updated: 2022/04/26 15:09:58 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_dist_to_wall(t_var *var)
{
	while (var->ray.hit == 0)
	{
		if (var->ray.sidedistx < var->ray.sidedisty)
		{
			var->ray.sidedistx += var->ray.deltadistx;
			var->ray.mapx += var->ray.stepx;
			var->ray.side = 0;
		}
		else
		{
			var->ray.sidedisty += var->ray.deltadisty;
			var->ray.mapy += var->ray.stepy;
			var->ray.side = 1;
		}
		if (var->map[var->ray.mapx][var->ray.mapy] == '1')
			var->ray.hit = 1;
	}
	if (var->ray.side == 0)
		var->ray.perpwalldist = ((double)var->ray.mapx - var->ray.posx
				+ (1 - (double)var->ray.stepx) / 2) / var->ray.raydirx;
	else
		var->ray.perpwalldist = ((double)var->ray.mapy - var->ray.posy
				+ (1 - (double)var->ray.stepy) / 2) / var->ray.raydiry;
}

void	get_wall_pos_on_screen(t_var *var)
{
	var->ray.lineheight = (int)(SCREEN_Y / var->ray.perpwalldist);
	var->ray.drawstart = -var->ray.lineheight / 2 + SCREEN_Y / 2;
	if (var->ray.drawstart < 0)
		var->ray.drawstart = 0;
	var->ray.drawend = SCREEN_Y - var->ray.drawstart;
}

void	draw_column(t_var *var, int x)
{
	int	y;

	y = -1;
	while (++y <= var->ray.drawstart)
		var->mlx.addr[y * var->mlx.line_len / 4 + x] = var->c;
	if (y <= var->ray.drawend)
		display_wall_line(var, x, y);
	y = var->ray.drawend;
	while (++y < SCREEN_Y)
		var->mlx.addr[y * var->mlx.line_len / 4 + x] = var->f;
}
