/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3D.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: andmadri <andmadri@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/05 13:49:31 by crasche       #+#    #+#                 */
/*   Updated: 2024/10/09 14:26:14 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// external functions:
# include <math.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>

// libft
# include "../lib/libft/include/libft.h"
// minilibx
# include "../lib/minilibx/mlx.h"

// marcos
# include <errno.h>
# include <fcntl.h>
# include <errno.h>
# include <stdbool.h>
# include <stdint.h>

# define DYNSTR 8
# define READBUF 1024

// KEYS
# ifndef LINUX
#  define LINUX 1
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_OPTION 65513
#  define KEY_SHIFT 65505
#  define KEY_ARROW_LEFT 65361
#  define KEY_ARROW_RIGHT 65363
#  define KEY_ARROW_UP 65362
#  define KEY_ARROW_DOWN 65364
#  define ESC 0xff1b
#  define STEP_SIZE 0.05
#  define TURN_STEP 0.05
# else
#  define LINUX 0
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_ARROW_LEFT 123
#  define KEY_ARROW_RIGHT 124
#  define KEY_ARROW_UP 126
#  define KEY_ARROW_DOWN 125
#  define ESC 53
#  define STEP_SIZE 0.05
#  define TURN_STEP 0.05
# endif

# define FORWARD 1
# define BACKWARD 2
# define LEFT 3
# define RIGHT 4

# define FOV 80

// create_trgb(0, 255, 0, 0)
# define RED 16711680
// create_trgb(0, 0, 255, 0)
# define BLUE 65280
// create_trgb(0, 0, 0, 255)
# define GREEN 255
// create_trgb(0, 255, 255, 255)
# define WHITE 16777215
// create_trgb(0, 0, 0, 0)
# define BLACK 0

// MINI_MAP
# define MINI_MAP 300
# define MM_BORDER_SIZE 3
# define MM_PLAYER_SIZE 10
# define MM_TILE_SIZE 30
# define VIEW_DISTANCE 120
// create_trgb(0, 20, 80, 200)
# define MM_PLAYER_COLOR 1331400
// create_trgb(0, 55, 55, 55)
# define MM_BORDER_COLOR 3618615
// create_trgb(0, 91, 76, 61)
# define MM_WALL_COLOR 5983293
// create_trgb(0, 148, 148, 148)
# define MM_FLOOR_COLOR 9737364
// create_trgb(0, 110, 177, 255)
# define MM_VOID_COLOR 7254527
# define MM_VIEW_COLOR WHITE

// MLX IMAGE
# define DRAW 0
# define DISPLAY 1

# define FPS 30

# define X 0
# define Y 1

# define EW 0
# define NS 1

# define NORTH 0
# define EAST 1
# define SOUTH 2
# define WEST 3

# define R 0
# define G 1
# define B 2

// MATH
# define RAD 0.01745329251
# define MOUSE_SENSITIVITY 5
# define MOUSE_OFFSET 50

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# ifndef BONUS
#  define BONUS 0
# endif

# ifndef CRAZY
#  define CRAZY 0
# endif

typedef struct s_mlx_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		offset;
	int		max_x;
	int		max_y;
}	t_mlx_img;

typedef struct s_raycaster
{
	t_mlx_img	*img;
	float		direction[2];
	float		r_start[2];
	float		length[2];
	float		step_size[2];
	float		step[2];
	float		intersect[2];
	float		final_distance;
	float		texture_perc;
	float		plane_magnitude;
	float		plane_scale;
	int			r_pos[2];
	int			x;
	int			line_height;
	int			wall_direction;
	int			col;
	bool		wall_found;
}	t_raycaster;

typedef struct s_minilx
{
	void		*mlx;
	void		*mlx_window;
	int			screen_x;
	int			screen_y;
	t_mlx_img	mini;
	t_mlx_img	big;
}	t_minilx;

typedef struct s_payer
{
	float	pos[2];
	float	direct[2];
	float	plane[2];
}	t_player;

typedef struct s_map_read
{
	char	*filename;
	int		fd;
	char	*read;
}	t_map_read;

typedef struct s_color
{
	char	*c_col;
	char	*f_col;
	char	**c_split;
	char	**f_split;
	int		c[3];
	int		f[3];
}	t_color;

typedef struct s_map
{
	t_map_read	map_read;
	t_color		color;
	char		**map;
	int			x_max;
	int			y_max;
	char		*n_tex;
	t_mlx_img	img_n;
	char		*e_tex;
	t_mlx_img	img_e;
	char		*s_tex;
	t_mlx_img	img_s;
	char		*w_tex;
	t_mlx_img	img_w;
	int			f_col;
	int			c_col;
}	t_map;

typedef struct s_keys
{
	int		mouse_step;
	bool	mouse_left;
	bool	mouse_right;
	bool	turn_left;
	bool	turn_right;
	bool	forward;
	bool	back;
	bool	strafe_left;
	bool	strafe_right;
	bool	exit;
	bool	mouse;
	bool	shift;
}	t_keys;

typedef struct s_data
{
	t_map		map;
	t_player	player;
	t_raycaster	ray;
	t_minilx	milx;
	t_keys		keys;
	uint64_t	frame_time;
	int			fps;
	int			mouse_x;
	int			mouse_y;
}	t_data;

// MAP
int			check_extension(char *str);
int			ft_atoi_rgb(const char *nptr);
int			map_init(t_data *data, t_map *map);
void		map_clear_line(t_data *data, t_map *map, int i);
void		map_parse(t_data *data, char **map);
void		map_clear(t_data *data, t_map *map);
void		map_color(t_data *data, t_color *color);
void		map_meta_copy(t_data *data, char *line, char **meta, int prefix);

// MINIMAP
void		draw_minimap_player(t_minilx *milx, int radius);
void		draw_minimap_tiles(t_data *data);
int			draw_minimap(t_data *data);

// MLX
int			finish_mlx(t_data *data);
void		hooks_mlx(t_data *data);
void		init_image(t_data *data);
void		key_hook_strafe(t_data *data);
void		key_hook_move(t_data *data);
void		key_hook_turn(t_data *data);
int			create_trgb(int t, int r, int g, int b);
int			img_get_pixel_color(t_mlx_img *img, int x, int y);
void		img_mlx_pixel_put(t_mlx_img *img, int x, int y, int color);
int			color_fraction(int c1, int c2, float fraction);
void		draw_background(t_data *data, t_minilx *milx, t_raycaster ray);
int			is_not_wall(t_data *data, float vx, float vy, int direction);

// RENDER
void		step_direction(t_raycaster *ray);
void		ray_caster(t_data *data, t_minilx *milx);
int			render(t_data *data);
void		draw_texture(t_data *data);

// UTILS
uint64_t	get_curr_time(void);
void		error(char *msg, t_data *data);
void		freenull(void **to_free);
void		free_all(t_data *data);

#endif // CUB3D_H
