/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nchok <nchok@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:34:50 by qtay              #+#    #+#             */
/*   Updated: 2024/12/15 04:03:49 by nchok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include "mlx.h"
# include "../libft/libft.h"

# define SUCCESS 0
# define FAILURE 1

# define VERTICAL 0
# define HORIZONTAL 1

# define WIN_HEIGHT 900
# define WIN_WIDTH 1280
# define TEXTURE_SIZE 64

/* KEYCODE */

# if defined(__APPLE__)
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_ESC 53
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124

# elif defined(__linux__)
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_ESC 65307
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
# endif

# define MOVE_STEP 0.0125
# define ROTATE_STEP 0.015

enum e_texture_index
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_cubfile
{
	int		file_rows;
	int		file_max_columns;
	char	**cub_file;
}	t_cubfile;

typedef struct s_textures
{
	int				size;
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				tex_index;
	int				tex_x;
	int				tex_y;
	double			increment;
	double			tex_pos;
}	t_textures;

typedef enum s_move
{
	FORWARD = 1,
	BACKWARD = 2,
	LEFT = 3,
	RIGHT = 4,
	CLOCKWISE = 5,
	ANTICLOCKWISE = 6
}	t_move;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	delta;
	int		has_moved;
	int		move_x;
	int		move_y;
	t_move	movement;
	int		rotate;
}	t_player;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	start_x;
	double	start_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perp_wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_rows;
	int			**textures;
	int			**screen_pixels;
	t_cubfile	file_info;
	t_textures	tex_info;
	t_player	player;
	t_ray		ray;
}	t_data;


/* UTILIZATION */
void			err_msg(char *msg);
void			free_double_arr(void **double_arr);

/* INITIALIZATION */
void			init_data(t_data *data);
void			init_ray(t_ray *ray);
void			init_player_dir(t_player *player);
void			init_mlx(t_data *data);
void			load_texture_img(t_data *data);

/* PARSING */
int				check_file(char *file_path);
int				get_file(char *file_path, t_data *data);
int				get_file_rows(char *file_path, t_cubfile *file_info);
int				dup_cub_file(char *file_path, t_cubfile *file_info);
int				get_textures(t_data *data);
void			extract_dir_textures(char *line, t_textures *tex_info);
void			extract_color_textures(char *line, t_textures *tex_info);
int				count_map_rows(char **cub_file);
char			*dup_map(char *line);
int				check_map(t_data *data);
int				check_file_open(char *file_path);
int				check_texture_ext(t_textures *tex_info);
int				check_rgb(int *rgb);
unsigned long	convert_rgb_hex(int *rgb);

/* POST-MAP CONTENT CHECK */
void			print_map(char **map);
int				check_post_map(t_data *data);
int				check_line_has_content(char *line);
int				check_spaces_line(char *line);
int				get_index_to_end_map(t_data *data);

/* RAYCASTING */
void			render_raycast(t_data *data);
void			raycasting(t_data *data, t_player *player);
void			init_raycasting(int x, t_ray *ray, t_player *player);
void			init_dda_algo(t_ray *ray, t_player *player);

/* INPUT HANDLER */
void			input_handler(t_data *data);
int				key_press_handler(int keycode, t_data *data);
int				key_release_handler(int keycode, t_data *data);

/* RENDER IF EVENT HAPPENS */
int				render_if_event(t_data *data);

/* PLAYER MOVEMENT */
int				move_player(t_data *data);
int				move_forward(t_data *data);
int				move_backward(t_data *data);
int				move_left(t_data *data);
int				move_right(t_data *data);
int				check_valid_move(t_data *data, double new_x, double new_y);
int				is_not_wall(t_data *data, double x, double y);

/* CAMERA MOVEMENT */
int				rotate_player(t_data *data);
int				rotate_clockwise(t_data *data);
int				rotate_anticlockwise(t_data *data);

/* FREE */
int				exit_cub3d(t_data *data);
void			clean_before_exit(t_data *data, int code);
void			free_data(t_data *data);
void			free_texture(t_textures *tex_info);
void			free_file_info(t_cubfile *file_info);


#endif
