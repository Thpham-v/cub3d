/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:57:40 by thpham-v          #+#    #+#             */
/*   Updated: 2022/04/25 06:47:06 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_free(char *str)
{
	if (!str)
		return (0);
	free(str);
	return (0);
}

int	get_next_line(int fd, char **line, char **temp, int ret)
{
	char		buff[BUFFER_SIZE + 1];

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (!ft_is_break_line(*temp) && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		*temp = ft_strjoin(*temp, buff);
	}
	*line = ft_get_line(*temp);
	*temp = ft_get_temp(*temp);
	if (!*line || !*temp)
		return (-1);
	if (ret == 0)
	{
		ret = ft_free(*temp);
		*temp = NULL;
		return (0);
	}
	return (1);
}
