#include"so_long.h"
#include "debug.h"

/* test */	double	time_diff(void)
/* test */	{
/* test */		static struct timespec	p = {0};
/* test */		struct timespec			n;
/* test */		unsigned int			sec;
/* test */		int						nsec;
/* test */
/* test */		if (!p.tv_sec)
/* test */		{
/* test */			clock_gettime(CLOCK_REALTIME, &p);
/* test */			return (0);
/* test */		}
/* test */		clock_gettime(CLOCK_REALTIME, &n);
/* test */		sec = n.tv_sec - p.tv_sec;
/* test */		nsec = n.tv_nsec - p.tv_nsec;
/* test */		p = n;
/* test */		return ((double)sec + (double)nsec / (1000 * 1000 * 1000));
/* test */	}

int main(int argc, char *argv[])
{
	t_info i;

TEST
	ft_bzero(&i, sizeof(t_info));
	check_arg(argc, argv);
	get_map(&i, argv[1]);
	i.mlx = mlx_init();
	i.win = mlx_new_window(i.mlx, i.map_w * BLOCKLEN, i.map_h * BLOCKLEN, "so_long");
	get_img(&i);
TEST
	base_win(&i);
TEST
	set_win(&i);
TEST
	mlx_loop_hook(i.mlx, game_main, &i);
	mlx_hook(i.win, 2, 0, set_gkey, &i);
	mlx_hook(i.win, 3, 0, rm_gkey, &i);
	mlx_hook(i.win, 17, 0, end_game, &i);
TEST
	mlx_loop(i.mlx);
	return (0);
}
void check_arg(int argc, char *argv[])
{
	if (argc < 2)
		error_exit("No map!\n");
	if (argc > 2)
		error_exit("Too many maps!\n");
	if (ft_strlen(argv[1]) < 4)
		error_exit("Invalid format!\n");
	if (ft_memcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		error_exit("Invalid format!\n");
	return ;
}

void get_map(t_info *i, char *name)
{
	read_map(i, 0, name, 0);
	convert_map(i);
	check_map(i);
	set_mob(i);
	return ;
}

void	read_map(t_info	*i, int	fd, char	*name, size_t	s)
{
	char	buf[BUFSIZ];
	ssize_t	j;

	if (name)
	{
		fd = open(name, O_RDONLY);
		if (fd < 0)
			error_exit("Unreadable file\n");
	}
	j = read(fd, buf, BUFSIZ);
	if (j < 0)
		error_exit("Read error\n");
	if (j == 0)
	{
		close(fd);
		i->map_c = malloc(s + j + 1);
		if (!i->map_c)
			error_exit("malloc errror\n");
		i->map_c[s + j] = '\0';
	}
	else
		read_map(i, fd, NULL, s + j);
	ft_memcpy(i->map_c, buf, j);
	return ;
}

void	convert_map(t_info	*i)
{
	size_t	j;
	size_t	c;
	size_t	l;

	j = 0;
	c = 0;
	while(i->map_c[j])
	{
		l = 0;
		while (i->map_c[j] && i->map_c[j] != '\n')
		{
			i->map_c[c] = i->map_c[j];
			j++;
			c++;
			l++;
		}
		if (l == j)
			i->map_w = l;
		if (i->map_w != l || i->map_c[j] != '\n')
{
TEST
			file_error(i->map_c);
}
		i->map_h++;
		j++;
	}
	i->map_c[c] = '\0';
	return ;
}

void	check_map(t_info	*i)
{
	size_t	m[5];

	ft_bzero(m, sizeof(size_t) * 5);
	while (i->map_c[m[0]])
	{
		if (is_map_elem(i->map_c[m[0]], m[0], i->map_w, i->map_h))
{
TEST
			file_error(i->map_c);
}
		if (i->map_c[m[0]] == 'E')
			m[1]++;
		else if (i->map_c[m[0]] == 'C')
			i->item++;
		else if (i->map_c[m[0]] == 'P')
			m[2]++;
		else if (i->map_c[m[0]] == 'M')
			m[3]++;
		else if (i->map_c[m[0]] == 'F')
			m[4]++;
		m[0]++;
	}
	if (!m[1] || !i->item || !m[2] || m[2] > 1 || m[3] > 1 || m[4] > 1)
{
TESTn(m[1])
TESTn(m[2])
TESTn(m[3])
TESTn(m[4])
			file_error(i->map_c);
}
	return ;
}

int is_map_elem(char elm, size_t c, size_t	w, size_t	h)
{
if (c % w == 0 && elm != '1')
TESTn(c % w == 0 && elm != '1')
if (c % w == w - 1 && elm != '1')
TESTn(c % w == w - 1 && elm != '1')
if (c < w - 1 && elm != '1')
TESTn(c < w - 1 && elm != '1')
if (c > w * (h - 1) && elm != '1')
TESTn(c > w * (h - 1) && elm != '1')
if (elm != '0' && elm != '1' && elm != 'E' && elm != 'C' && elm != 'P' && elm != 'W' && elm != 'M' && elm != 'F')
TESTn(elm != '0' && elm != '1' && elm != 'E' && elm != 'C' && elm != 'P' && elm != 'W' && elm != 'M' && elm != 'F')

	if ((c % w == 0 && elm != '1') \
	|| (c % w == w - 1 && elm != '1') \
	|| (c < w - 1 && elm != '1') \
	|| (c > w * (h - 1) && elm != '1') \
	|| (elm != '0' && elm != '1' && elm != 'E' && elm != 'C' \
		&& elm != 'P' && elm != 'W' && elm != 'M' && elm != 'F'))
		return (1);
	return (0);
}

void	set_mob(t_info	*i)
{
	size_t	j;

	j = 0;
	while (i->map_c[j])
	{
		if (i->map_c[j] == 'P')
			reset_mob(i, &(i->mp), j, BACK);
		else if (i->map_c[j] == 'M')
			i->mm = j;
		else if (i->map_c[j] == 'F')
			i->mf = j;
		else if (i->map_c[j] == 'W')
			set_Wmob(i, j);
		j++;
	}
	return ;
}

void	reset_mob(t_info	*i, t_mob *m, size_t c, int d)
{
	m->to = c;
	m->nowx = (c % i->map_w) * BLOCKLEN;
	m->nowy = (c / i->map_w) * BLOCKLEN;
	m->direct = d % 4;
	return ;
}

void	set_Wmob(t_info	*i, size_t c)
{
	t_mob *new;
	t_mob *last;

	new = malloc(sizeof(t_mob));
	if (!new)
	{
		while(i->mw)
		{
			new = i->mw;
			i->mw = i->mw->next;
			free(new);
		}
TEST
		file_error(i->map_c);
	}
	reset_mob(i, new, c, my_rand(i->buf));
	last = i->mw;
	if (!last)
		i->mw = new;
	else
	{
		while(last->next)
			last = last->next;
		last->next = new;
	}
	return ;
}

void	get_img(t_info	*i)
{
	int	buf;

TESTp(i->mlx)
TESTn(open(FILE_0, O_RDONLY))
	i->img_0 = mlx_xpm_file_to_image(i->mlx, FILE_0, &buf, &buf);
	i->img_p[FRONT] = mlx_xpm_file_to_image(i->mlx, FILE_Pf, &buf, &buf);
	i->img_p[BACK] = mlx_xpm_file_to_image(i->mlx, FILE_Pb, &buf, &buf);
	i->img_p[LEFT] = mlx_xpm_file_to_image(i->mlx, FILE_Pl, &buf, &buf);
	i->img_p[RIGHT] = mlx_xpm_file_to_image(i->mlx, FILE_Pr, &buf, &buf);
	i->img_c = mlx_xpm_file_to_image(i->mlx, FILE_C, &buf, &buf);
	i->img_e = mlx_xpm_file_to_image(i->mlx, FILE_E, &buf, &buf);
	i->img_w[0] = i->img_0;
	i->img_w[1] = mlx_xpm_file_to_image(i->mlx, FILE_W01, &buf, &buf);
	i->img_w[2] = mlx_xpm_file_to_image(i->mlx, FILE_W02, &buf, &buf);
	i->img_w[3] = mlx_xpm_file_to_image(i->mlx, FILE_W03, &buf, &buf);
	i->img_w[4] = mlx_xpm_file_to_image(i->mlx, FILE_W04, &buf, &buf);
	i->img_w[5] = mlx_xpm_file_to_image(i->mlx, FILE_W05, &buf, &buf);
	i->img_w[6] = mlx_xpm_file_to_image(i->mlx, FILE_W06, &buf, &buf);
	i->img_w[7] = mlx_xpm_file_to_image(i->mlx, FILE_W07, &buf, &buf);
	i->img_w[8] = mlx_xpm_file_to_image(i->mlx, FILE_W08, &buf, &buf);
	i->img_w[9] = mlx_xpm_file_to_image(i->mlx, FILE_W09, &buf, &buf);
	i->img_w[10] = mlx_xpm_file_to_image(i->mlx, FILE_W10, &buf, &buf);
TESTp(FILE_0)
TESTp(FILE_Pf)
TESTp(FILE_Pb)
TESTp(FILE_Pl)
TESTp(FILE_Pr)
TESTp(FILE_C)
TESTp(FILE_E)
TESTp(FILE_W01)
TESTp(FILE_W02)
TESTp(FILE_W03)
TESTp(FILE_W04)
TESTp(FILE_W05)
TESTp(FILE_W06)
TESTp(FILE_W07)
TESTp(FILE_W08)
TESTp(FILE_W09)
TESTp(FILE_W10)
TESTp(i->img_0)
TESTp(i->img_p[FRONT])
TESTp(i->img_p[BACK] )
TESTp(i->img_p[LEFT] )
TESTp(i->img_p[RIGHT])
TESTp(i->img_c)
TESTp(i->img_e)
TESTp(i->img_w[0])
TESTp(i->img_w[1])
TESTp(i->img_w[2])
TESTp(i->img_w[3])
TESTp(i->img_w[4])
TESTp(i->img_w[5])
TESTp(i->img_w[6])
TESTp(i->img_w[7])
TESTp(i->img_w[8])
TESTp(i->img_w[9])
TESTp(i->img_w[10])
	return ;
}

void	set_win(t_info	*i)
{
	size_t	j;

	j = 0;
	while (i->map_c[j])
	{
		if (i->map_c[j] == 'C')
			mlx_put_image_to_window(i->mlx, i->win, i->img_c, (j % i->map_w) * BLOCKLEN, (j / i->map_w) * BLOCKLEN);
		else if (i->map_c[j] == 'E')
			mlx_put_image_to_window(i->mlx, i->win, i->img_e, (j % i->map_w) * BLOCKLEN, (j / i->map_w) * BLOCKLEN);
		else if (i->map_c[j] == 'W')
			mlx_put_image_to_window(i->mlx, i->win, i->img_w[9], (j % i->map_w) * BLOCKLEN, (j / i->map_w) * BLOCKLEN);
		if (i->map_c[j] == 'P' || i->map_c[j] == 'W')
			i->map_c[j] = '0';
		else if(i->map_c[j] == 'M' || i->map_c[j] == 'F')
			i->map_c[j] = '1';
		j++;
	}
	mlx_put_image_to_window(i->mlx, i->win, i->img_p[BACK], i->mp.nowx, i->mp.nowy);
	return ;
}

void	base_win(t_info	*i)
{
	size_t	j;
	int		buf;
	void	*imgA;
	void	*imgB;

	imgA = mlx_xpm_file_to_image(i->mlx, FILE_0b, &buf, &buf);
	imgB = mlx_xpm_file_to_image(i->mlx, FILE_1b, &buf, &buf);
	j = 0;
TESTp(imgA)
TESTp(imgB)
	while (i->map_c[j])
	{
		if (i->map_c[j] == '1')
			mlx_put_image_to_window(i->mlx, i->win, imgB, (j % i->map_w) * BLOCKLEN, (j / i->map_w) * BLOCKLEN);
		else
			mlx_put_image_to_window(i->mlx, i->win, imgA, (j % i->map_w) * BLOCKLEN, (j / i->map_w) * BLOCKLEN);
		j++;
	}
TESTp(imgA)
TESTp(imgB)
	mlx_destroy_image(i->mlx, imgA);
	mlx_destroy_image(i->mlx, imgB);
TESTp(imgA)
TESTp(imgB)
	imgA = mlx_xpm_file_to_image(i->mlx, FILE_M, &buf, &buf);
	imgB = mlx_xpm_file_to_image(i->mlx, FILE_F, &buf, &buf);
	mlx_put_image_to_window(i->mlx, i->win, imgB, (i->mm % i->map_w) * BLOCKLEN, (i->mm / i->map_w) * BLOCKLEN);
	mlx_put_image_to_window(i->mlx, i->win, imgB, (i->mf % i->map_w) * BLOCKLEN, (i->mf / i->map_w) * BLOCKLEN);
	mlx_destroy_image(i->mlx, imgA);
	mlx_destroy_image(i->mlx, imgB);
	return ;
}

int game_main(void *p)
{
	t_info	*i;

	i = p;
	if (i->situ == START && i->newkey != NO_KEY)
		i->situ = GAME;
	else if (i->situ == GAME)
		game_process(i);
	else if (i->situ == SUCCESS)
	{
		success_win(i);
		i->situ = END;
	}
	else if (i->situ == FALE)
	{
		fale_win(i);
		i->situ = END;
	}
	else if (i->situ == END && i->newkey == ESC_KEY)
	{
		mlx_destroy_window(i->mlx, i->win);
		exit(0);
	}
	return (0);
}

void	game_process(t_info	*i)
{
	if (!(i->time))
		turnw(i);
	if (i->time == i->reset)
		i->key_ok = 1;
	if (i->key == NO_KEY && i->newkey != NO_KEY && i->key_ok)
		i->reset = i->time;
	i->key = i->newkey;
	if (i->key == ESC_KEY)
		end_game(i);
	else if (i->time == i->reset)
	{
		turnp(i, i->key);
		if (i->key != NO_KEY)
		i->key_ok = 0;
	}
	if (!(i->time % TURN))
		move(i);
	i->time++;
	i->time &= WEIFHT;
	return ;
}

void	turnw(t_info	*i)
{
	t_mob	*m;

	m = i->mw;
	while (m)
	{
		Wmob(i, m);
		m = m->next;
	}
	return ;
}


void Wmob(t_info *i, t_mob *m)
{
	int	able[4];

	reset_mob(i, m, m->to, m->direct);
	advance(i, m, able);
	next_direct(i, m, able);
	go_straight(i, m);
	return ;
}

void	turnp(t_info	*i, int key)
{
	int	able[4];

	if (key >= 4)
	{
		reset_mob(i, &(i->mp), i->mp.to, i->mp.direct);
		return ;
	}
	reset_mob(i, &(i->mp), i->mp.to, key);
	item_get(i);
	advance(i, &(i->mp), able);
	if (able[key])
		go_straight(i, &(i->mp));
	return ;
}

void	item_get(t_info	*i)
{
	if (i->map_c[i->mp.to] == 'C')
	{
		i->item--;
		i->map_c[i->mp.to] = '0';
	}
	else if (i->map_c[i->mp.to] == 'E' && !(i->item))
		i->situ = SUCCESS;
	return ;
}

void go_straight(t_info	*i, t_mob *m)
{
	int	c;

	if (i->key == RIGHT)
		c = 1;
	else if (i->key == FRONT)
		c = i->map_w * -1;
	else if (i->key == LEFT)
		c = -1;
	else if(i->key == RIGHT)
		c = i->map_w;
	else
		c = 0;
	m->to += c;
	return ;
}


void m_killer1(t_info	*i, t_mob	*m);
void m_killer(t_info	*i, t_mob	*m)
{
	size_t	mx;
	size_t	my;

	if (!i->mm)
		return ;
	mx = (i->mm % i->map_w) * BLOCKLEN;
	my = (i->mm / i->map_w) * BLOCKLEN;
	if (mx < i->mp.nowx)
		mx = i->mp.nowx - mx;
	else
		mx -= i->mp.nowx;
	if (my < i->mp.nowy)
		my = i->mp.nowy - my;
	else
		my -= i->mp.nowy;
	if (my < mx)
		mx = my;
	if (mx > BLOCKLEN)
		return;
	else
		m_killer1(i, m);
	return ;
}

void m_killer1(t_info	*i, t_mob	*m)
{
	size_t	mx;
	size_t	my;

	mx = (i->mm % i->map_w) * BLOCKLEN;
	my = (i->mm / i->map_w) * BLOCKLEN;
	if (mx < m->nowx)
		mx = m->nowx - mx;
	else
		mx -= m->nowx;
	if (my < m->nowy)
		my = m->nowy - my;
	else
		my -= m->nowy;
	if (my < mx)
		mx = my;
	if (mx <= BLOCKLEN)
		m->direct = DEAD;
	return;
}

size_t distance(t_mob	*m1, t_mob	*m2)
{
	size_t	x;
	size_t	y;

	if (m1->nowx > m2->nowx)
		x = m1->nowx - m2->nowx;
	else
		x = m2->nowx - m1->nowx;
	if (m1->nowy > m2->nowy)
		y = m1->nowy - m2->nowy;
	else
		y = m2->nowy - m1->nowy;
	if (x < y)
		return (x);
	return (y);
}

void	advance(t_info	*i, t_mob	*m, int	*able)
{
	int isp;

	isp = m == &(i->mp);
	able[FRONT] = (i->map_c[m->to - i->map_w] != '1' && \
		i->map_c[m->to - i->map_w] != 'E') || (i->map_c[m->to - i->map_w] == 'E' && isp);
	able[LEFT] = (i->map_c[m->to - 1] != '1' && \
		i->map_c[m->to - 1] != 'E') || (i->map_c[m->to - 1] == 'E' && isp);
	able[BACK] = (i->map_c[m->to + i->map_w] != '1' && \
		i->map_c[m->to + i->map_w] != 'E') || (i->map_c[m->to + i->map_w] == 'E' && isp);
	able[RIGHT] = (i->map_c[m->to + 1] != '1' && \
		i->map_c[m->to + 1] != 'E') || (i->map_c[m->to + 1] == 'E' && isp);
	return ;
}

void next_direct1(t_info	*i, t_mob	*m, int *able);
void next_direct(t_info	*i, t_mob *m, int *able)
{
	if (m->direct >= 4)
		return ;
	if (able[m->direct])
	{
		if ((able[(m->direct + 3) % 4] || able[(m->direct + 1) % 4]) \
		&& my_rand(i->buf) % 2)
		{
			if (able[(m->direct + 3) % 4])
			{
				if (able[(m->direct + 1) % 4] && my_rand(i->buf) % 2)
					m->direct = (m->direct + 1) % 4;
				else
					m->direct = (m->direct + 3) % 4;
			}
			else
				m->direct = (m->direct + 1) % 4;
		}
		else
			m->direct = m->direct;
	}
	else
		next_direct1(i, m, able);
	return ;
}

void next_direct1(t_info	*i, t_mob	*m, int *able)
{
	if (able[(m->direct + 3) % 4] || able[(m->direct + 1) % 4])
	{
		if (able[(m->direct + 3) % 4])
		{
			if (able[(m->direct + 1) % 4] && my_rand(i->buf) % 2)
				m->direct = (m->direct + 1) % 4;
			else
				m->direct = (m->direct +3) % 4;
		}
		else
			m->direct = (m->direct + 1) % 4;
	}
	else if (able[(m->direct + 2) % 4])
		m->direct = (m->direct + 2) % 4;
	else
		m->direct = NO_KEY;
	return ;
}

void move(t_info	*i)
{
	t_mob	*m;

	clean_win(i);
	move_mob(i, &(i->mp));
	m = i->mw;
	while(m)
	{
		move_mob(i,m);
		m = m->next;
	}
	move_result(i);
	e_win(i);
	p_win(i);
	w_win(i);
	c_win(i);
	return ;
}

void clean_win(t_info	*i)
{
	t_mob	*m;

	mlx_put_image_to_window(i->mlx, i->win, i->img_0, i->mp.nowx, i->mp.nowy);
	m = i->mw;
	while (m)
	{
		mlx_put_image_to_window(i->mlx, i->win, i->img_0, m->nowx, m->nowy);
		m = m->next;
	}
	return ;
}

void move_mob(t_info	*i, t_mob	*m)
{
	if (m->direct == NO_KEY || m->direct >= DEAD \
	|| ((m->to % i->map_w) * BLOCKLEN == m->nowx && (m->to / i->map_w) * BLOCKLEN == m->nowy))
	{
		if (m->direct >= DEAD)
			m->direct++;
		return ;
	}
	if (m->direct == FRONT)
		m->nowy--;
	else if (m->direct == RIGHT)
		m->nowx++;
	else if (m->direct == BACK)
		m->nowy++;
	else if (m->direct == LEFT)
		m->nowx--;
	return ;
}

void	move_result(t_info	*i)
{
	t_mob *m;

	i->mw = rm_w(i->mw);
	m = i->mw;
	while (m)
	{
		m_killer(i,m);
		m = m->next;
	}
	m = i->mw;
	while (m)
	{
		if (distance(m, &(i->mp)) < DEATHLEN && i->situ != SUCCESS)
		{
			i->situ = FALE;
			break ;
		}
		m = m->next;
	}
	return ;
}

t_mob	*rm_w(t_mob *start)
{
	t_mob *m;
	t_mob *mn;

	if (!start)
		return (NULL);
	m = start;
	while(m->next)
	{
		if (m->next->direct >= DEAD + BLOCKLEN)
		{
			mn = m->next;
			m->next = mn->next;
			free(mn);
		}
		else
			m = m->next;
	}
	if (start->direct >= DEAD + BLOCKLEN)
	{
		m = start->next;
		free(start);
		return (m);
	}
	return (start);
}

void	e_win(t_info	*i)
{
	size_t	j;

	j = 0;
	while (i->map_c[j])
	{
		if (i->map_c[j] == 'E')
			mlx_put_image_to_window(i->mlx, i->win, i->img_e, (j % i->map_w) * BLOCKLEN, (j / i->map_w) * BLOCKLEN);
		j++;
	}
	return ;
}

void	p_win(t_info	*i)
{
	mlx_put_image_to_window(i->mlx, i->win, i->img_p[i->mp.direct], i->mp.nowx, i->mp.nowy);
	return ;
}

void	w_win(t_info	*i)
{
	t_mob *m;
	size_t j;

	m = i->mw;
	while (m)
	{
		if (m->direct >= DEAD)
		{
			if (m->direct % 2)
				mlx_put_image_to_window(i->mlx, i->win, i->img_w[9], m->nowx, m->nowy);
			else
				mlx_put_image_to_window(i->mlx, i->win, i->img_w[10], m->nowx, m->nowy);
		}
		else
		{
			j = f_presence(i, m);
			if (j)
				mlx_put_image_to_window(i->mlx, i->win, i->img_w[j], m->nowx, m->nowy);
		}
		m = m->next;
	}
	return ;
}

size_t	f_presence1(t_info	*i, t_mob *m, size_t	fp);
size_t	f_presence(t_info	*i, t_mob *m)
{
	size_t	fx;
	size_t	fy;

	if (!i->mf)
		return (f_presence1(i, m, 5 * BLOCKLEN));
	fx = (i->mf % i->map_w) * BLOCKLEN;
	fy = (i->mf / i->map_w) * BLOCKLEN;
	if (fx < i->mp.nowx)
		fx = i->mp.nowx - fx;
	else
		fx -= i->mp.nowx;
	if (fy < i->mp.nowy)
		fy = i->mp.nowy - fy;
	else
		fy -= i->mp.nowy;
	if (fy < fx)
		fx = fy;
	return (f_presence1(i, m, fx));
}

size_t	f_presence1(t_info	*i, t_mob *m, size_t	fp)
{
	size_t	fx;
	size_t	fy;

	fx = i->mp.nowx;
	fy = i->mp.nowy;
	if (fx < m->nowx)
		fx = m->nowx - fx;
	else
		fx -= m->nowx;
	if (fy < m->nowy)
		fy = m->nowy - fy;
	else
		fy -= m->nowy;
	if (fy < fx)
		fx = fy;
	if ((fp / BLOCKLEN) > 5)
		fp = 1;
	else
		fp = 5 - (fp / BLOCKLEN) + 1;
	fy = (16 * fp * BLOCKLEN) / fx;
	if (fy < 7)
		return (0);
	else if (fy > 16)
		return (9);
	return (fy - 7);
}

void	c_win(t_info	*i)
{
	size_t	j;

	j = 0;
	while (i->map_c[j])
	{
		if (i->map_c[j] == 'C')
			mlx_put_image_to_window(i->mlx, i->win, i->img_c, (j % i->map_w) * BLOCKLEN, (j / i->map_w) * BLOCKLEN);
		j++;
	}
	return ;
}

int set_gkey(int	key, void	*p)
{
	t_info	*i;
	i = p;
TESTn(key)
	if (key == 0 || key == 123)
		i->newkey = LEFT;
	else if (key == 1 || key == 125)
		i->newkey = BACK;
	else if (key == 2 || key == 124)
		i->newkey = RIGHT;
	else if (key == 13 || key == 126)
		i->newkey = FRONT;
	else if (key == 53)
		i->newkey = ESC_KEY;
	else
		i->newkey = NO_KEY;
	return(0);
}

int	rm_gkey(int	key, void	*p)
{
	t_info	*i;
	i = p;

	(void)key;
	i->newkey = NO_KEY;
	return(0);
}

void	error_exit(char *msg)
{
	if (msg)
		write(STDOUT_FILENO, msg, ft_strlen(msg));
	exit(1);
	return ;
}

void	file_error(char *must_free)
{
	free(must_free);
	write(STDOUT_FILENO, "Invalid file\n", 12);
	exit(1);
}

void frree_content(t_info *i)
{
	t_mob *m;

	mlx_destroy_image(i->mlx,i->img_0);
	mlx_destroy_image(i->mlx,i->img_p[FRONT]);
	mlx_destroy_image(i->mlx,i->img_p[BACK]);
	mlx_destroy_image(i->mlx,i->img_p[LEFT]);
	mlx_destroy_image(i->mlx,i->img_p[RIGHT]);
	mlx_destroy_image(i->mlx,i->img_c);
	mlx_destroy_image(i->mlx,i->img_e);
	mlx_destroy_image(i->mlx,i->img_w[1]);
	mlx_destroy_image(i->mlx,i->img_w[2]);
	mlx_destroy_image(i->mlx,i->img_w[3]);
	mlx_destroy_image(i->mlx,i->img_w[4]);
	mlx_destroy_image(i->mlx,i->img_w[5]);
	mlx_destroy_image(i->mlx,i->img_w[6]);
	mlx_destroy_image(i->mlx,i->img_w[7]);
	mlx_destroy_image(i->mlx,i->img_w[8]);
	mlx_destroy_image(i->mlx,i->img_w[9]);
	mlx_destroy_image(i->mlx,i->img_w[10]);
	free(i->map_c);
	m = i->mw;
	while (m)
	{
		free(m);
		m = m->next;
	}
	return ;
}

int		end_game(void *p)
{
	t_info *i;

	i = p;
	frree_content(i);
	exit(0);
	return (0);
}

int		my_rand(u_int8_t *base)
{
	int		r;

	base[0] &= 0x7;
	if (!base[0])
	{
		sha256(base + 1, 32, base + 1);
		base[0] = 0;
	}
	ft_memcpy(&r, base + 1 + base[0], sizeof(int));
	if (r < 0)
		r = (r + 1) * -1;
	base[0]++;
	return (r);
}

void	success_win(t_info *i)
{
	frree_content(i);
TEST
	return ;
}

void	fale_win(t_info *i)
{
	frree_content(i);
TEST
	return ;
}
