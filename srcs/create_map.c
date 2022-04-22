/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 02:10:03 by thpham-v          #+#    #+#             */
/*   Updated: 2022/04/22 09:41:08 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_map(t_var *var)
{
	int	i;

	i = 0;
	if (!var->map)
		return ;
	while (var->map[i])
	{
		free(var->map[i]);
		i++;
	}
	free(var->map);
	var->map = NULL;
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

int	ft_count_map(char *file, t_var *var, int ret)
{
	int	nb_char_temp;
	int	i;
	char	*line;
	
	i = 0;
	if (open_file(file, var) == -1)
		return (-1);
	while (ret)
	{
		while (i < var->what_line)
		{
			ret = get_next_line(var->fd, &line, &var->temp, 1);
			i++;
			free(line);
			line = NULL;
		}
		ret = get_next_line(var->fd, &line, &var->temp, 1);
		nb_char_temp = ft_strlen(line);
		if (nb_char_temp > var->nb_char)
			var->nb_char = nb_char_temp;
		var->nb_l++;
		free(line);
		line = NULL;
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
	/*while (i < var->nb_l)
	{
		var->map[i] = malloc(sizeof(char) * var->nb_char);
		if (!var->map[i])
			return (0);
		i++;
	}*/
	return (1);
}

void	ft_final_map(char *file, t_var *var, int ret)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	ret = 1;
	var->fd = open(file, O_RDONLY);
	while (ret == 1)
	{
		while (i < var->what_line)
		{
			ret = get_next_line(var->fd, &line, &var->temp, 1);
			i++;
			free(line);
			line = NULL;
		}
		ret = get_next_line(var->fd, &line, &var->temp, 1);
		var->map[j] = line;
		j++;
		//free(line);
		line = NULL;
	}
	var->map[j] = NULL;
}
