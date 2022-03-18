/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:36:29 by thpham-v          #+#    #+#             */
/*   Updated: 2022/03/18 05:11:00 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int	i;
	
	i = 0;
	char	**map;
	
	map = malloc(sizeof(char *) * 5);
	while (i != 3)
	{
		map[i] = malloc(sizeof(char) * 10);
		i++;
	}	
	map[0] = "1 1 1 1 1";
	map[1] = "1 0 0 0 1";
	map[2] = "1 1 0 1 1";
	map[3] = "1 1 1 1 1";
	map[4] = NULL;
	/*printf("%s\n", map[0]);
	printf("%s\n", map[1]);	
	printf("%s\n", map[2]);*/
	printf("%d\n", parsing_map(map));
	return (0);
}