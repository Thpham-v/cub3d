/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:38:05 by thpham-v          #+#    #+#             */
/*   Updated: 2022/03/19 02:32:46 by thpham-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "libft.h"

# define BUFFER_SIZE	4096

typedef struct	s_var
{
	char **map;
	char *line;
	int	nb_l;
	int	nb_char;
	int	fd;
}				t_var;

int	parsing_map(char **map);
int	open_file(char *file, t_var *var);
int	ft_read_line(char *file, t_var *var, int ret);
int	ft_malloc_map(t_var *var);
void	ft_final_map(char *file, t_var *var, int ret);
int		get_next_line(int fd, char **line, int ret);
char	*ft_get_temp(char *str);
char	*ft_get_line(char *str);
int		ft_is_break_line(char *str);
int		ft_free(char *str);

#endif