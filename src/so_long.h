/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:18:04 by ryoakira          #+#    #+#             */
/*   Updated: 2022/06/26 20:18:05 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../minilibx_mms_20200219/mlx.h"

typedef struct s_info
{
	void			*mlx;
	void			*win;
	size_t			map_w;
	size_t			map_h;
	char			*map_c;
	size_t			mc;
	size_t			item;
	void			*img_0;
	void			*img_p;
	int				newkey;
	int				key;
	int				key_ok;
	size_t			time;
	size_t			reset;
	unsigned int	walk;
}	t_info;

# define BUFSIZ 64
# define BLOCKLEN 30
# define WEIFHT 0x7ff
# define FILE_0B "img/floor_big.xpm"
# define FILE_1B "img/wall_big.xpm"
# define FILE_0 "img/floor.xpm"
# define FILE_P "img/anya0.xpm"
# define FILE_C "img/peanuts.xpm"
# define FILE_E "img/tv.xpm"

enum
{
	NO_KEY,
	FRONT,
	BACK,
	LEFT,
	RIGHT,
	ESC_KEY
};
//map.c
void	get_map(t_info *i, int argc, char *argv[]);
void	read_map(t_info	*i, int	fd, char	*name, size_t	s);
void	convert_map(t_info	*i);
void	check_map(t_info	*i);
//map_util.c
void	check_arg(int argc, char *argv[]);
int		is_map_elem(char elm, size_t c, size_t	w, size_t	h);
//seting.c
void	get_img(t_info	*i);
void	set_win(t_info	*i);
//game.c
int		game_process(void *p);
void	move(t_info	*i, int key);
//key.c
int		set_key(int	key, void	*p);
int		rm_key(int	key, void	*p);
//end.c
void	error_exit(char *msg);
void	file_error(char *must_free, char *msg);
int		end_game(void *i);
//libft
size_t	ft_strlen(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
int		ft_printf(const char	*fmt, ...);

#endif
