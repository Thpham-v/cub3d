/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 04:15:10 by thpham-v          #+#    #+#             */
/*   Updated: 2022/04/22 09:44:16 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_map_params(t_var *var)
{
	if (var->no == NULL || var->so == NULL ||
	var->we == NULL || var->ea == NULL)
	//var->sp == NULL || !var->rx || !var->ry)
		return (0);
	if (var->f == -1 || var->c == -1)
		return (0);
	return (1);
}

int		is_empty(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}

int		through_space(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

void	get_path_texture(t_var *var, char *line, char **path)
{
	int i;

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
	if (line[i + through_space(&line[i])] != '\0')
		ft_error(var, "Invalid path texture precision in .cub\n");
	*path = ft_strndup(line, i);
}

void	get_rgb(t_var *var, char *line, int *color)
{
	int r;
	int g;
	int b;

	if (line[1] == ' ')
		line += 2;
	else
		line += 1;
	//if (!check_color_line(line) || *color != -1)
		//ft_error(var, "Invalid RGB precision in .cub\n");
	r = ft_atoi(line);
	line = ft_strchr(line, ',') + 1;
	g = ft_atoi(line);
	line = ft_strchr(line, ',') + 1;
	line += through_space(line);
	b = ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line += through_space(line);
	if (*line != '\0')
		ft_error(var, "Invalid RGB precision in .cub\n");
	if (r > 255 || g > 255 || b > 255)
		ft_error(var, "Invalid RGB value in .cub\n");
	*color = r << 16 | g << 8 | b;
}

void	get_map_params(char *line, t_var *var)
{
	line += through_space(line);
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
	{
		printf("Invalid precision in .cub\n");
		ft_exit(var);
	}
}

void	parsing_file(char *file, t_var *var)
{
	int		ret;

	ret = 1;
	if (open_file(file, var) == -1)
		return ;
	while (ret == 1)
	{
		ret = get_next_line(var->fd, &var->line, &var->temp, 1);
		if (!is_map_params(var))
		{
			get_map_params(var->line, var);
			var->what_line++;
		}
		else if (is_empty(var->line) && var->nb_l == 0)
			var->what_line++;
		free(var->line);
		var->line = NULL;
	}
	close(var->fd);
	if (!is_map_params(var))
		exit(1);
}

/*int	pars(char *file, t_var *var)
{
	if ((ft_read_line(argv[1], &var, 1) != -1))
	{
		ft_malloc_map(&var);
		ft_final_map(argv[1], &var, 1);
	}
	if (parsing_map(&var) == 0)

}*/