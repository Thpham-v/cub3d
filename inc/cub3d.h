/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:38:05 by thpham-v          #+#    #+#             */
/*   Updated: 2022/04/26 10:49:33 by thpham-v         ###   ########.fr       */
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

typedef struct s_var
{
	char	**map;
	char	*line;
	char	*temp;
	int		nb_l;
	int		nb_char;
	int		fd;
	int		pos_x;
	int		pos_y;
	int		x;
	int		y;
	int		count;
	char	player_dir;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*sol;
	char	*plafond;
	int		c;
	int		f;
	int		what_line;
}				t_var;

void		parsing_map(t_var *var);
void		open_file(char *file, t_var *var);
int			ft_count_map(char *file, t_var *var, int ret);
int			ft_malloc_map(t_var *var);
void		ft_final_map(char *file, t_var *var, int ret);
int			get_next_line(int fd, char **line, char **temp, int ret);
char		*ft_get_temp(char *str);
char		*ft_get_line(char *str);
int			ft_is_break_line(char *str);
int			ft_free(char *str);
void		ft_free_tab(t_var *var);
void		get_map_params(char *line, t_var *var);
void		parsing_file(char *file, t_var *var);
int			is_map_params(t_var *var);
void		get_map_params(char *line, t_var *var);
void		ft_error(t_var *var, char *error_msg);
int			ft_exit(t_var *var);
void		ft_free_map(t_var *var);
int			skip_space(char *str);
int			is_empty(char *str);

#endif