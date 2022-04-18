/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:38:05 by thpham-v          #+#    #+#             */
/*   Updated: 2022/04/18 06:44:43 by thpham-v         ###   ########.fr       */
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
	char		**map;
	char		*line;
	int			nb_l;
	int			nb_char;
	int			fd;
	int			pos_x;
	int			pos_y;
	char		player_dir;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*sol;
	char		*plafond;
	int			c;
	int			f;
}				t_var;

int	parsing_map(t_var *var);
int	open_file(char *file, t_var *var);
int	ft_read_line(char *file, t_var *var, int ret);
int	ft_malloc_map(t_var *var);
void	ft_final_map(char *file, t_var *var, int ret);
int		get_next_line(int fd, char **line, int ret);
char	*ft_get_temp(char *str);
char	*ft_get_line(char *str);
int		ft_is_break_line(char *str);
int		ft_free(char *str);
void	ft_free_tab(char **tab);
void	get_map_params(char *line, t_var *var);

#endif