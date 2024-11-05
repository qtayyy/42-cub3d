/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qtay <qtay@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:34:50 by qtay              #+#    #+#             */
/*   Updated: 2024/11/05 17:00:47 by qtay             ###   ########.fr       */
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

# define WIN_HEIGHT 480
# define WIN_WIDTH 640
# define TEXTURE_SIZE 64

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

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
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

void	err_msg(char *msg);
int		check_file(char *file_path);

#endif
