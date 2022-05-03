/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 06:27:35 by htizi             #+#    #+#             */
/*   Updated: 2022/04/26 13:42:09 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press(int keycode, t_var *var)
{
	if (keycode == ESC)
		ft_exit(var);
	else if (keycode == FORWARD_W)
		var->move.forward = 1;
	else if (keycode == BACK_S)
		var->move.back = 1;
	else if (keycode == LEFT_A)
		var->move.left = 1;
	else if (keycode == RIGHT_D)
		var->move.right = 1;
	else if (keycode == ROTATE_L)
		var->move.rotate_left = 1;
	else if (keycode == ROTATE_R)
		var->move.rotate_right = 1;
	return (0);
}

int	key_release(int keycode, t_var *var)
{
	if (keycode == FORWARD_W)
		var->move.forward = 0;
	else if (keycode == BACK_S)
		var->move.back = 0;
	else if (keycode == LEFT_A)
		var->move.left = 0;
	else if (keycode == RIGHT_D)
		var->move.right = 0;
	else if (keycode == ROTATE_L)
		var->move.rotate_left = 0;
	else if (keycode == ROTATE_R)
		var->move.rotate_right = 0;
	return (0);
}
