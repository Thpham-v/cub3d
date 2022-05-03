/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:13:43 by htizi             #+#    #+#             */
/*   Updated: 2022/04/26 15:37:27 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture_images(t_var *var)
{
	var->textures[0].img = mlx_xpm_file_to_image(var->mlx.mlx_ptr,
			var->no, &(var->textures[0].width), &(var->textures[0].height));
	if (var->textures[0].img == NULL)
		ft_error(var, "Impossible to get NO texture\n");
	var->textures[1].img = mlx_xpm_file_to_image(var->mlx.mlx_ptr, var->so,
			&(var->textures[1].width), &(var->textures[1].height));
	if (var->textures[1].img == NULL)
		ft_error(var, "Impossible to get SO texture\n");
	var->textures[2].img = mlx_xpm_file_to_image(var->mlx.mlx_ptr, var->we,
			&(var->textures[2].width), &(var->textures[2].height));
	if (var->textures[2].img == NULL)
		ft_error(var, "Impossible to get WE texture\n");
	var->textures[3].img = mlx_xpm_file_to_image(var->mlx.mlx_ptr, var->ea,
			&(var->textures[3].width), &(var->textures[3].height));
	if (var->textures[3].img == NULL)
		ft_error(var, "Impossible to get EA texture\n");
}

void	get_texture_addresses(t_var *var)
{
	var->textures[0].addr = (int *)mlx_get_data_addr(var->textures[0].img,
			&var->textures[0].bpp,
			&var->textures[0].line_len, &var->textures[0].endian);
	var->textures[1].addr = (int *)mlx_get_data_addr(var->textures[1].img,
			&var->textures[1].bpp,
			&var->textures[1].line_len, &var->textures[1].endian);
	var->textures[2].addr = (int *)mlx_get_data_addr(var->textures[2].img,
			&var->textures[2].bpp,
			&var->textures[2].line_len, &var->textures[2].endian);
	var->textures[3].addr = (int *)mlx_get_data_addr(var->textures[3].img,
			&var->textures[3].bpp,
			&var->textures[3].line_len, &var->textures[3].endian);
}

void	set_textures(t_var *var)
{
	get_texture_images(var);
	get_texture_addresses(var);
}
