/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 02:10:03 by thpham-v          #+#    #+#             */
/*   Updated: 2022/04/18 04:22:01 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

int	open_file(char *file, t_var *var)
{
	var->fd = open(file, O_DIRECTORY);
	if (var->fd != -1)
	{
		printf("Error it is a directory\n");
		return (-1);
	}
	var->fd = open(file, O_RDONLY);
	if (var->fd == -1)
	{
		printf("open() file .cub failed\n");
		return (-1);
	}
	return (0);
}

int	ft_read_line(char *file, t_var *var, int ret)
{
	int	nb_char_temp;
	char	*line;

	if (open_file(file, var) == -1)
		return (-1);
	while (ret)
	{
		ret = get_next_line(var->fd, &line, 1);
		if (line[0] != '\0')
		{
			nb_char_temp = ft_strlen(line);
			if (nb_char_temp > var->nb_char)
				var->nb_char = nb_char_temp;
			var->nb_l++;
		}
		free(line);
	}
	var->nb_l++;
	return (ret);
}

int	ft_malloc_map(t_var *var)
{
	int	i;

	i = 0;
	var->map = malloc(sizeof(char *) * var->nb_l);
	if (!var->map)
		return (0);
	while (i < var->nb_l)
	{
		var->map[i] = malloc(sizeof(char) * var->nb_char);
		if (!var->map[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_final_map(char *file, t_var *var, int ret)
{
	int		i;
	char	*line;

	i = 0;
	ret = 1;
	var->fd = open(file, O_RDONLY);
	while (ret)
	{
		ret = get_next_line(var->fd, &line, 1);
		if (line[0] != '\0')
		{
			var->map[i] = line;
			i++;
		}
	}
	var->map[i] = NULL;
}