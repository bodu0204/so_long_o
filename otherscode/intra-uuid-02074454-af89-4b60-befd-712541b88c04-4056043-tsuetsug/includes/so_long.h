/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 12:52:09 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/17 22:02:23 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include	<unistd.h>
# include	<stdlib.h>
# include	<stdio.h>
# include   <errno.h>
# include   <fcntl.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../minilibx/mlx.h"

typedef struct s_data {
	void	*astronaut;
	void	*background;
	void	*planet;
	void	*earth;
	void	*blackhole;
	int		width;
	int		height;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map {
	char	*str;
	char	**content;
	int		col;
	int		row;
	int		player_x;
	int		player_y;
}				t_map;

typedef struct s_game {
	void	*mlx;
	void	*win;
	int		move_x;
	int		move_y;
	int		move_count;
	t_map	map;
	t_data	img;
}				t_game;

/* so_long_utils.c */
void	ft_error(char *error_message, t_game *game);
void	download_images(t_game *game);
int		destroy_window(t_game *game);

/* ft_mlx.c */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/* import_file.c */
void	read_file(char *file_name, t_game *game);
void	import_map(char *file_name, t_game *game);
void	convert_map_2D_array(t_game *game);
void	sizeof_col_row(t_game *game);

/* import_file_error.c */
void	validate_file_name(char *file_name, t_game *game);
void	validate_wall(t_game *game);
void	validate_map_components(t_game *game);
int		count_map_components(char map_components, t_game *game);

/* key_control.c */
char	*search_element_addr(t_game *game, char element);
void	key_press_proc(t_game *game);
int		key_press(int keycode, t_game *game);

/* destroy_window */
void	safe_free(char **ptr);
void	free_map(t_game *game);
int		destroy_window(t_game *game);

#endif
