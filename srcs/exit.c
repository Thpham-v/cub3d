/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:54:26 by thpham-v          #+#    #+#             */
/*   Updated: 2022/05/04 01:54:56 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_destroy(t_var *var)
{
	if (var->mlx.img)
		mlx_destroy_image(var->mlx.mlx_ptr, var->mlx.img);
	if (var->textures[0].img)
		mlx_destroy_image(var->mlx.mlx_ptr, var->textures[0].img);
	if (var->textures[1].img)
		mlx_destroy_image(var->mlx.mlx_ptr, var->textures[1].img);
	if (var->textures[2].img)
		mlx_destroy_image(var->mlx.mlx_ptr, var->textures[2].img);
	if (var->textures[3].img)
		mlx_destroy_image(var->mlx.mlx_ptr, var->textures[3].img);
	if (var->mlx.mlx_win)
		mlx_destroy_window(var->mlx.mlx_ptr, var->mlx.mlx_win);
	if (var->mlx.mlx_ptr)
	{
		mlx_destroy_display(var->mlx.mlx_ptr);
		free(var->mlx.mlx_ptr);
	}
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
	mlx_destroy(var);
	exit(0);
}
