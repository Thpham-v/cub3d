/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:36:29 by thpham-v          #+#    #+#             */
/*   Updated: 2022/04/22 06:58:03 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_var var;
	int	i;
	
	i = 0;
	ft_bzero(&var, sizeof(t_var));
	var.f = -1;
	var.c = -1;
	parsing_file(argv[1], &var);
	if ((ft_count_map(argv[1], &var, 1) != -1))
	{
		ft_malloc_map(&var);
		ft_final_map(argv[1], &var, 1);
	}
	if (parsing_map(&var) == 0)
	{
		while (i < var.nb_l - 1)
		{
			printf("%s\n", var.map[i]);
			i++;
		}
	}
	ft_exit(&var);	
	return (0);
}