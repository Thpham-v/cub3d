/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 02:10:03 by thpham-v          #+#    #+#             */
/*   Updated: 2022/04/25 07:19:56 by thpham-v         ###   ########.fr       */
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

void	open_file(char *file, t_var *var)
{
	int	i;
	int	good;

	i = 0;
	good = 0;
	while (file[i])
	{
		if (file[i] == '.')
		{
			if (file[i + 1] == 'c' && file[i + 2] == 'u' && file[i + 3] == 'b')
				good = 1;
		}
		i++;
	}
	if (good != 1)
		ft_error(var, "Wrong extension\n");
	var->fd = open(file, O_DIRECTORY);
	if (var->fd != -1)
		ft_error(var, "It is a directory\n");
	var->fd = open(file, O_RDONLY);
	if (var->fd == -1)
		ft_error(var, "Open file .cub failed\n");
}

int	ft_count_map(char *file, t_var *var, int ret)
{
	int		nb_char_temp;
	int		i;
	char	*line;

	i = 0;
	open_file(file, var);
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

void	ft_final_map(char *file, t_var *var, int ret)
{
	int		i;
	int		j;
	char	*line;

	var->map = malloc(sizeof(char *) * var->nb_l);
	if (!var->map)
		return ;
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
	}
	var->map[j] = NULL;
}
