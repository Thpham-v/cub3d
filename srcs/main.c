/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:36:29 by thpham-v          #+#    #+#             */
/*   Updated: 2022/04/25 06:40:47 by thpham-v         ###   ########.fr       */
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
	// part of the H
	ft_exit(&var);
	return (0);
}
