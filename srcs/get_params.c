/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 04:15:10 by thpham-v          #+#    #+#             */
/*   Updated: 2022/04/25 06:51:40 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_color_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] != ' ' && line[i] != ',' && !ft_isdigit(line[i]))
			return (0);
	line += skip_space(line);
	if (!ft_isdigit(*line))
		return (0);
	line = ft_strchr(line, ',');
	if (!line)
		return (0);
	line++;
	line += skip_space(line);
	if (!ft_isdigit(*line))
		return (0);
	line = ft_strchr(line, ',');
	if (!line)
		return (0);
	line++;
	line += skip_space(line);
	if (!ft_isdigit(*line))
		return (0);
	return (1);
}

void	get_path_texture(t_var *var, char *line, char **path)
{
	int	i;

	if (!ft_strchr(line, '.') || !ft_strchr(line, '/') || *path != NULL)
		ft_error(var, "Invalid path texture precision in .cub\n");
	if (line[0] == 'S' && (line[1] == ' ' || line[1] == '.'))
		line += 1;
	else
		line += 2;
	while (*line != '.')
	{
		if (*line != ' ')
			ft_error(var, "Invalid path texture precision in .cub\n");
		line++;
	}
	i = 0;
	while (line[i] > 32 && line[i] < 127)
		i++;
	if (line[i + skip_space(&line[i])] != '\0')
		ft_error(var, "Invalid path texture precision in .cub\n");
	*path = ft_strndup(line, i);
}

void	get_rgb(t_var *var, char *line, int *color)
{
	int	r;
	int	g;
	int	b;

	if (line[1] == ' ')
		line += 2;
	else
		line += 1;
	if (!check_color_line(line) || *color != -1)
		ft_error(var, "Invalid RGB precision in .cub\n");
	r = ft_atoi(line);
	line = ft_strchr(line, ',') + 1;
	g = ft_atoi(line);
	line = ft_strchr(line, ',') + 1;
	line += skip_space(line);
	b = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line += skip_space(line);
	if (*line != '\0')
		ft_error(var, "Invalid RGB precision in .cub\n");
	if (r > 255 || g > 255 || b > 255)
		ft_error(var, "Invalid RGB value in .cub\n");
	*color = r << 16 | g << 8 | b;
}

void	get_map_params(char *line, t_var *var)
{
	line += skip_space(line);
	if (line[0] == 'S' && line[1] == 'O')
		get_path_texture(var, line, &var->so);
	else if (line[0] == 'N' && line[1] == 'O')
		get_path_texture(var, line, &var->no);
	else if (line[0] == 'E' && line[1] == 'A')
		get_path_texture(var, line, &var->ea);
	else if (line[0] == 'W' && line[1] == 'E')
		get_path_texture(var, line, &var->we);
	else if (line[0] == 'C' && (line[1] == ' ' || ft_isdigit(line[1])))
		get_rgb(var, line, &var->c);
	else if (line[0] == 'F' && (line[1] == ' ' || ft_isdigit(line[1])))
		get_rgb(var, line, &var->f);
	else if (!is_empty(line))
		ft_error(var, "Invalid precision in .cub\n");
}
