#ifndef SO_LONG_H
#define SO_LONG_H


#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../minilibx_mms_20200219/mlx.h"

typedef struct s_mob
{
	size_t		nowx;
	size_t		nowy;
	size_t		to;
	int			direct;
	struct s_mob	*next;
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
	size_t	walk;
	void	*img_0;
	void	*img_1;
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
	u_int8_t	buf[33];
}	t_info;




#define BLOCKLEN 30
#define WEIFHT 0x7ff
#define DEATHLEN 10
#define MAMLEN 30
#define DADLEN 150
#define TURN (WEIFHT / BLOCKLEN)

#define FILE_0b		"img/floor_bonus_big.xpm"
#define FILE_1b		"img/wall_big.xpm"
#define FILE_0		"img/floor_bonus.xpm"
#define FILE_1		"img/wall.xpm"
#define FILE_Pf		"img/anya3.xpm"
#define FILE_Pb		"img/anya0.xpm"
#define FILE_Pl		"img/anya1.xpm"
#define FILE_Pr		"img/anya2.xpm"
#define FILE_C		"img/peanuts.xpm"
#define FILE_E		"img/tv.xpm"
#define FILE_M		"img/mam.xpm"
#define FILE_F		"img/dad.xpm"
#define FILE_W01	"img/book001.xpm"
#define FILE_W02	"img/book003.xpm"
#define FILE_W03	"img/book005.xpm"
#define FILE_W04	"img/book010.xpm"
#define FILE_W05	"img/book020.xpm"
#define FILE_W06	"img/book030.xpm"
#define FILE_W07	"img/book050.xpm"
#define FILE_W08	"img/book080.xpm"
#define FILE_W09	"img/book100.xpm"
#define FILE_W10	"img/book999.xpm"
#define FILE_HAPPY	"img/happy_end.xpm"
#define FILE_BAD	"img/bad_end.xpm"

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
void	get_map(t_info *i, char *name);
void	read_map(t_info	*i, int	fd, char	*name, size_t	s);
void	convert_map(t_info	*i);
void	check_map(t_info	*i);
int		is_map_elem(char elm, size_t c, size_t	w, size_t	h);
void	set_mob(t_info	*i);
void	reset_mob(t_info	*i, t_mob *m, size_t c, int d);
void	set_Wmob(t_info	*i, size_t c);
void	get_img(t_info	*i);
void	set_win(t_info	*i);
void	base_win(t_info	*i);
int		game_main(void *p);
void	game_process(t_info	*i);
void	turnw(t_info	*i);
void	Wmob(t_info *i, t_mob *m);
void	turnp(t_info	*i, int key);
void	item_get(t_info	*i);
void	go_straight(t_info	*i, t_mob *m);
void	m_killer(t_info	*i, t_mob	*m);
size_t	distance(t_mob	*m1, t_mob	*m2);
void	advance(t_info	*i, t_mob	*m, int	*able);
void	next_direct(t_info	*i, t_mob *m, int *able);
void	move(t_info	*i);
void	clean_win(t_info	*i);
void	move_mob(t_info	*i, t_mob	*m);
void	move_result(t_info	*i);
t_mob	*rm_w(t_mob *start);
void	e_win(t_info	*i);
void	p_win(t_info	*i);
void	w_win(t_info	*i);
size_t	f_presence(t_info	*i, t_mob *m);
void	c_win(t_info	*i);
int		set_gkey(int	key, void	*p);
int		rm_gkey(int	key, void	*p);
void	error_exit(char *msg);
void	file_error(char *must_free);
void	frree_content(t_info *i);
int		end_game(void *p);
int		my_rand(u_int8_t *base);
void	success_win(t_info *i);
void	fale_win(t_info *i);
void	itosu(char	*str, unsigned int	n);


void		sha256(const void *data, size_t len, uint8_t *hash);

size_t	ft_strlen(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);

#endif
