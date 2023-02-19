/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fausto <fausto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:26:42 by rruiz-la          #+#    #+#             */
/*   Updated: 2022/11/29 17:01:05 by fausto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>

# define PI				3.14
# define ONE_DEGREE		0.017444
# define MAPCELL		64
# define PLAYER			4
# define WALK_STEP		4
# define VALID_CHAR 	"10NSEW "
# define KEY_ESC		65307
# define KEY_W			119
# define KEY_S			115 
# define KEY_A			97
# define KEY_D			100
# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_LEFT		65361
# define KEY_RIGHT		65363

typedef struct s_txtr_addr {
	void		*txtr;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x;
	int			y;
	__uint32_t	*buffer;
}				t_txtr_addr;

typedef struct s_txtr
{
	t_txtr_addr	no;
	t_txtr_addr	so;
	t_txtr_addr	we;
	t_txtr_addr	ea;
}				t_txtr;

typedef struct s_map
{
	char	**map;
	char	*texture_no;
	char	*texture_so;
	char	*texture_we;
	char	*texture_ea;
	int		*f;
	int		*c;
	char	player;
	int		closed_wall;
	int		fd;
	int		max_height;
	int		max_line;
}	t_map;

typedef struct s_player
{
	double	x;
	double	y;
	float	angle;
	int		cell_x;
	int		cell_y;
}	t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			win_height;
	int			win_width;
	void		*wall;
	int			mini_map_x;
	int			mini_map_y;
	char		*dst;
}	t_game;

typedef struct s_ray
{
	double	angle;
	double	degree;
	int		ray_size;
	int		wall_height;
	double	map_x_pos;
	double	map_y_pos;
	int		cell_x_pos;
	int		cell_y_pos;
	char	hited_wall;
	int		step;
	int		cell_x;
	int		cell_y;
	double	delta_x;
	double	delta_y;
	float	ty;
	int		ty_init;
	float	ty_step;
	float	ty_offset;
	int		ray;
}	t_ray;

typedef struct s_data
{
	t_map		*map;
	t_player	*player;
	t_game		*game;
	t_ray		*ray;
	t_txtr		txtr;
	int			pix_y_pos;
}	t_data;

typedef struct s_minimap
{
	char	*dst;
	int		x;
	int		y;
}	t_mini;

//ray casting
void	ray_casting_wall(t_data *data);
void	print_celing(t_data *data, int *i, int j);
void	print_wall(t_data *data, int *i, int j, int w);
void	print_floor(t_data *data, int *i, int j);
int		calc_color(t_data *data, int w, int ty_init, float ty);

//map
void	ray_tracing(t_data *data, t_ray *ray, int i);
int		ray_x(t_map *map, t_player **player, t_ray *ray);
int		is_in_range(t_map *map, t_player **player, t_ray *ray);
void	track_ray_cell(t_ray *ray, t_player **player);
int		ray_y(t_data *data, t_player **player, t_ray *ray);
void	fill_ray_struct(t_data *data, t_ray *ray, int i);

//game
void	looping(t_data *data);
void	init_game(t_data *data);
int		key_press(int key, t_data *data);
int		key_release(int key, t_data *data);

//screen setup
void	image_setup(t_data *data);
void	move_foward_backward(int key, t_player **player, char **map);
void	move_left(int key, t_player **player, char **map);
void	move_right(int key, t_player **player, char **map);
void	turn_left_right(int key, t_data *data);

//validation
void	initial_validation(t_data *data, int argc, char *argv[]);
void	file_validation(t_data *data, char *file, char *ext);
void	map_header_validation(t_data *data);
void	color_validation(t_data *data, char **line, int **color);
char	*get_color_value(char *line);
void	clean_spaces_in_param(char ***tmp_color);
char	*get_value(char *line);
int		rgb_to_int(int r, int g, int b);

//map_validation
int		built_map(t_data *data);
void	map_validation(t_data *data);
void	wall_validation(t_data *data);
int		check_line(char **line);

//exit_error
int		clean(t_data *data);
void	free_map_struct(t_data *data);
void	exit_error(t_data *data, char *token, int flag);

#endif