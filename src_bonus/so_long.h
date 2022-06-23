#ifndef SO_LONG_H
#define SO_LONG_H


#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "mlx.h"

typedef struct s_mob
{
	size_t		nowx;
	size_t		nowy;
	size_t		to;
	int			direct;
	struct s_request	*next;
}	t_mob;

typedef struct s_info
{
	void	*mlx;
	void	*win;
	size_t	map_w;
	size_t	map_h;
	char	*map_c;
	size_t	item;
	size_t	mm;
	size_t	mf;
	t_mob	mp;
	t_mob	*mw;
	void	*img_0;
	void	*img_p[4];
	void	*img_c;
	void	*img_e;
	void	*img_w[11];
	int		situ;
	int		newkey;
	int		key;
	int		key_ok;
	size_t	time;
	size_t	reset;
	size_t	reset;
	u_int8_t	buf[33];
}	t_info;




#define BLOCKLEN 30
#define WEIFHT 0x7ff
#define DEATHLEN 10
#define MAMLEN 30
#define DADLEN 150

#define TURN (WEIFHT / BLOCKLEN)
#define FILE_0b		""
#define FILE_1b		""
#define FILE_0		""
#define FILE_Pf		""
#define FILE_Pb		""
#define FILE_Pl		""
#define FILE_Pr		""
#define FILE_C		""
#define FILE_E		""
#define FILE_M		""
#define FILE_F		""
#define FILE_W01	""
#define FILE_W02	""
#define FILE_W03	""
#define FILE_W04	""
#define FILE_W05	""
#define FILE_W06	""
#define FILE_W07	""
#define FILE_W08	""
#define FILE_W09	""
#define FILE_W10	""

#define FRONT 0
#define RIGHT 1
#define BACK 2
#define LEFT 3
#define ESC_KEY 4
#define NO_KEY 5
#define DEAD 6

#define START 0
#define GAME 1
#define SUCCESS 2
#define FALE 3
#define END 4



void	check_arg(int argc, char *argv[]);
void	read_map(t_info	*i, int	fd, char	*name, size_t	s);
void	get_map(t_info *i, char *name)
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

void		sha256(const void *data, size_t len, uint8_t *hash);

size_t	ft_strlen(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);

#endif
