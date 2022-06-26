#ifndef SO_LONG_H
#define SO_LONG_H


#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "mlx.h"

typedef struct s_info
{
	void	*mlx;
	void	*win;
	size_t	map_w;
	size_t	map_h;
	char	*map_c;
	size_t	mc;
	size_t	item;
	void	*img_0;
	void	*img_1;
	void	*img_p;
	void	*img_c;
	void	*img_e;
}	t_info;

#define BLOCKLEN 30
#define WEIFHT 0x7ff
#define FILE_0b "img/floor_big.xpm"
#define FILE_1b "img/wall_big.xpm"
#define FILE_0 "img/floor.xpm"
#define FILE_1 "img/wall.xpm"
#define FILE_P "img/anya0.xpm"
#define FILE_C "img/peanuts.xpm"
#define FILE_E "img/tv.xpm"

enum
{
	NO_KEY,
	FRONT,
	BACK,
	LEFT,
	RIGHT,
	ESC_KEY
};

void	get_map(t_info *i, int argc, char *argv[]);
void	read_map(t_info	*i, int	fd, char	*name, size_t	s);
void	set_map(t_info	*i);
void	get_img(t_info	*i);
void	set_win(t_info	*i);
int		game_process(void *p);
void	move(t_info	*i, int key);
void	load(unsigned long int i);
int		set_gkey(int	key, void	*p);
int		rm_gkey(int	key, void	*p);
void	error_exit(char *msg);
void	file_error(char *must_free);
int		end_game(void *i);


size_t	ft_strlen(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);

#endif
