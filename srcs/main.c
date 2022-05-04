/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htizi <htizi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:36:29 by thpham-v          #+#    #+#             */
/*   Updated: 2022/04/26 14:26:01 by htizi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_var	var;
	int		i;

	i = 0;
	ft_bzero(&var, sizeof(t_var));
	var.f = -1;
	var.c = -1;
	if (argc != 2)
		ft_error(&var, "Incorrect number of arguments\n");
	parsing_file(argv[1], &var);
	if ((ft_count_map(argv[1], &var, 1) != -1))
		ft_final_map(argv[1], &var, 1);
	parsing_map(&var);
	init_raycasting(&var);
	cub3d(&var);
	ft_exit(&var);
	return (0);
}
