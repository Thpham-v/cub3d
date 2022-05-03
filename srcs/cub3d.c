/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 06:15:00 by htizi             #+#    #+#             */
/*   Updated: 2022/04/26 15:38:25 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d(t_var *var)
{
	var->mlx.mlx_ptr = mlx_init();
	if (var->mlx.mlx_ptr == NULL)
		ft_error(var, "mlx_init() has failed\n");
	set_textures(var);
	var->mlx.img = mlx_new_image(var->mlx.mlx_ptr, SCREEN_X, SCREEN_Y);
	var->mlx.addr = (int *)mlx_get_data_addr(var->mlx.img,
			&var->mlx.bpp, &var->mlx.line_len, &var->mlx.endian);
	var->mlx.mlx_win = mlx_new_window(var->mlx.mlx_ptr,
			SCREEN_X, SCREEN_Y, "Cub3d");
	mlx_hook(var->mlx.mlx_win, 33, 1L << 17, ft_exit, var);
	mlx_hook(var->mlx.mlx_win, 02, 1L << 0, key_press, var);
	mlx_hook(var->mlx.mlx_win, 03, 1L << 1, key_release, var);
	mlx_loop_hook(var->mlx.mlx_ptr, raycasting, var);
	mlx_loop(var->mlx.mlx_ptr);
}
