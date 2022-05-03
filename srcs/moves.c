/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 09:26:03 by htizi             #+#    #+#             */
/*   Updated: 2022/04/26 11:53:18 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_var *var, double speed)
{
	if (var->move.forward == 1)
	{
		if (var->map[(int)(var->ray.posx + (var->ray.dirx
					* speed * 2))][(int)var->ray.posy] == '0')
				var->ray.posx += var->ray.dirx * speed;
		if (var->map[(int)(var->ray.posx)][(int)(var->ray.posy
			+ (var->ray.diry * speed * 2))] == '0')
			var->ray.posy += var->ray.diry * speed;
	}
}

void	move_back(t_var *var, double speed)
{
	if (var->move.back == 1)
	{
		if (var->map[(int)(var->ray.posx - (var->ray.dirx
					* speed * 2))][(int)(var->ray.posy)] == '0')
			var->ray.posx -= var->ray.dirx * speed;
		if (var->map[(int)(var->ray.posx)][(int)(var->ray.posy -
					(var->ray.diry * speed * 2))] == '0')
			var->ray.posy -= var->ray.diry * speed;
	}
}

void	move_left(t_var *var, double speed)
{
	if (var->move.left == 1)
	{
		if (var->map[(int)(var->ray.posx - var->ray.diry
				* speed * 2)][(int)var->ray.posy] == '0')
		var->ray.posx -= var->ray.diry * speed;
		if (var->map[(int)var->ray.posx][(int)(var->ray.posy
			+ var->ray.dirx * (speed * 2))] == '0')
			var->ray.posy += var->ray.dirx * speed;
	}
}

void	move_right(t_var *var, double speed)
{
	if (var->move.right == 1)
	{
		if (var->map[(int)(var->ray.posx + var->ray.diry
				* speed * 2)][(int)var->ray.posy] == '0')
			var->ray.posx += var->ray.diry * speed;
		if (var->map[(int)var->ray.posx][(int)(var->ray.posy
			- var->ray.dirx * (speed * 2))] == '0')
			var->ray.posy -= var->ray.dirx * speed;
	}
}

void	move_and_rotate_player(t_var *var)
{
	double	speed;

	speed = var->move.move_speed;
	if (var->move.forward == 1 || var->move.back == 1)
		speed = var->move.move_speed / 1.5;
	move_forward(var, speed);
	move_back(var, speed);
	move_left(var, speed);
	move_right(var, speed);
	rotate_left(var);
	rotate_right(var);
}
