/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thpham-v <thpham-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:38:05 by thpham-v          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/03 05:59:26 by thpham-v         ###   ########.fr       */
=======
/*   Updated: 2022/04/26 10:49:33 by thpham-v         ###   ########.fr       */
>>>>>>> d96357da57388ef11cc1c08d06da79cbae459b40
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
# define SCREEN_X		1680
# define SCREEN_Y		1200
# define ESC			65307
# define FORWARD_W		119
# define BACK_S			115
# define LEFT_A			97
# define RIGHT_D		100
# define ROTATE_L		65361
# define ROTATE_R		65363

<<<<<<< HEAD
typedef struct s_mlx {
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img;
	int				*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
}	t_mlx;

typedef struct s_ray{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	double		raydirx;
	double		raydiry;
	double		camerax;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			x;
}	t_ray;

typedef struct s_move
{
	int			forward;
	int			back;
	int			left;
	int			right;
	int			rotate_left;
	int			rotate_right;
	double		move_speed;
	double		rotation_speed;
}				t_move;

typedef struct s_texel
{
	int			dir;
	double		wallx;
	int			texx;
	int			texy;
	double		step;
	double		texpos;
}				t_texel;

typedef struct s_var
{
	char		**map;
	char		*line;
	char		*temp;
	int			nb_l;
	int			nb_char;
	int			fd;
	int			pos_x;
	int			pos_y;
	int			count;
	char		player_dir;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*sol;
	char		*plafond;
	int			c;
	int			f;
	int			what_line;
	int			x;
	int			y;
	t_ray		ray;
	t_move		move;
	t_mlx		mlx;
	t_mlx		textures[4];
	t_texel		texel;
=======
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
>>>>>>> d96357da57388ef11cc1c08d06da79cbae459b40
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
<<<<<<< HEAD
void		init_raycasting(t_var *var);
void		cub3d(t_var *var);
int			key_press(int keycode, t_var *var);
int			key_release(int keycode, t_var *var);
int			raycasting(t_var *var);
void		move_and_rotate_player(t_var *var);
void		rotate_right(t_var *var);
void		rotate_left(t_var *var);
void		get_dist_to_wall(t_var *var);
void		get_wall_pos_on_screen(t_var *var);
void		draw_column(t_var *var, int x);
void		display_wall_line(t_var *var, int x, int y);
void		set_textures(t_var *var);
void		set_ray(t_var *var, int x);
void		mlx_destroy(t_var *var);

#endif
=======

#endif
>>>>>>> d96357da57388ef11cc1c08d06da79cbae459b40
