/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 05:20:54 by kkohki            #+#    #+#             */
/*   Updated: 2022/03/23 22:59:05 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MAX 64800
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_EXIT		17 
# define TILE_SIZE 32

# define KEY_ESC			53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <sys/types.h>
# include <math.h>
# include <string.h>
# include "../minilibx_mms/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct s_map
{
	size_t		x_size;
	size_t		y_size;
	char		*filename;
	char		**map;
}		t_map;

typedef struct s_image
{
	void	*player;
	void	*wall;
	void	*collectable;
	void	*exit;
	void	*empty;
}		t_image;

typedef struct s_player
{
	size_t	x_position;
	size_t	y_position;
}	t_player;

typedef struct s_num
{
	size_t	c_flag_num;
	size_t	c_num;
	size_t	move_num;
}	t_num;

typedef struct s_info
{
	t_num		num;
	t_player	player;
	t_image		image;
	t_map		map_info;
	void		*mlx;
	void		*window;
}	t_info;

/*main.c*/
void	put_error(char *str);
void	error_check(t_info	*info);
/*read_map.c*/
int		read_map(t_info *info);
void	validate_enclose_wall(t_info *info);
void	check_str(t_info	*info);
/*assign_image_to_window.c*/
void	create_window(t_info *info);
void	assign_xpm_image(t_info *info);
/*map.c*/
int		input_player_postion(t_info *info);
void	check_len(t_info	*info);
/*event.c*/
void	set_event(t_info *info);
/*free.c*/
int		free_element(t_info *info);
int		check_each_postion(t_info *info);
#endif

// __attribute__((destructor))
// static void destructor() {
// 	system("leaks -q so_long");
// }

// # define KEY_ESC			65307
// # define KEY_W			119
// # define KEY_A			97
// # define KEY_S			115
// # define KEY_D			100