/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:36:29 by thpham-v          #+#    #+#             */
/*   Updated: 2022/03/19 02:30:42 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_var var;
	int	i;
	
	i = 0;
	ft_bzero(&var, sizeof(t_var));
	if ((ft_read_line(argv[1], &var, 1) != -1))
	{
		ft_malloc_map(&var);
		ft_final_map(argv[1], &var, 1);
	}
	while (i < var.nb_l)
	{
		printf("%s\n", var.map[i]);
		i++;
	}
	return (0);
}