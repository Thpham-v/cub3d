/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 02:09:54 by htizi             #+#    #+#             */
/*   Updated: 2022/04/26 13:43:58 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	raycasting(t_var *var)
{
	var->ray.x = 0;
	while (var->ray.x < SCREEN_X)
	{
		set_ray(var, var->ray.x);
		get_dist_to_wall(var);
		get_wall_pos_on_screen(var);
		draw_column(var, var->ray.x);
		var->ray.x++;
	}
	mlx_put_image_to_window(var->mlx.mlx_ptr,
		var->mlx.mlx_win, var->mlx.img, 0, 0);
	move_and_rotate_player(var);
	return (0);
}
