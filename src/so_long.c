#include"so_long.h"
#include"debug.h"

int g_key;

int main(int argc, char *argv[])
{
	t_info i;

	ft_bzero(&i, sizeof(t_info));
	i.walk = 1;
	get_map(&i, argc, argv);
	i.mlx = mlx_init();
	i.win = mlx_new_window(i.mlx, i.map_w * BLOCKLEN, i.map_h * BLOCKLEN, "so_long");
	get_img(&i);
	set_win(&i);
	mlx_loop_hook(i.mlx, game_process, &i);
	mlx_hook(i.win, 2, 0, set_gkey, &i);
	mlx_hook(i.win, 3, 0, rm_gkey, &i);
	mlx_hook(i.win, 17, 0, end_game, &i);
	mlx_loop(i.mlx);
 return (0);
}

void	get_map(t_info *i, int argc, char *argv[])
{
	check_arg(argc, argv);
	read_map(i, 0, argv[1], 0);
	convert_map(i);
	check_map(i);
	return ;
}

void	check_arg(int argc, char *argv[])
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
	ft_memcpy(i->map_c + s, buf, j);
	return ;
}

void	convert_map(t_info	*i)
{
	size_t	j;
	size_t	c;
	size_t	l;

	j = 0;
	c = 0;
	while (i->map_c[j])
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
			file_error(i->map_c, "line errror\n");
		i->map_h++;
		j++;
	}
	i->map_c[c] = '\0';
	return ;
}

void	check_map(t_info	*i)
{
	size_t	m[3];

	ft_bzero(m, sizeof(size_t) * 3);
	while (i->map_c[m[0]])
	{
		if (is_map_elem(i->map_c[m[0]], m[0], i->map_w, i->map_h))
			file_error(i->map_c, "charractor error\n");
		if (i->map_c[m[0]] == 'E')
			m[1]++;
		else if (i->map_c[m[0]] == 'C')
			i->item++;
		else if (i->map_c[m[0]] == 'P')
		{
			i->mc = m[0];
			m[2]++;
		}
		m[0]++;
	}
	if (!m[1] || !i->item || !m[2] || m[2] > 1)
		file_error(i->map_c, "charractor sum error\n");
	return ;
}

int	is_map_elem(char elm, size_t c, size_t	w, size_t	h)
{
	if ((c % w == 0 && elm != '1') \
	|| (c % w == w - 1 && elm != '1') \
	|| (c < w - 1 && elm != '1') \
	|| (c > w * (h - 1) && elm != '1') \
	|| (elm != '0' && elm != '1' && elm != 'E' && elm != 'C' \
		&& elm != 'P' && elm != 'W' && elm != 'M' && elm != 'F'))
		return (1);
	return (0);
}

void	get_img(t_info	*i)
{
	int	buf;

	i->img_0 = mlx_xpm_file_to_image(i->mlx, FILE_0, &buf, &buf);
	i->img_p = mlx_xpm_file_to_image(i->mlx, FILE_P, &buf, &buf);
	return ;
}

void	set_win1(t_info	*i);
void	set_win(t_info	*i)
{
	size_t	j;
	int		buf;
	void	*img0;
	void	*img1;

	img0 = mlx_xpm_file_to_image(i->mlx, FILE_0b, &buf, &buf);
	img1 = mlx_xpm_file_to_image(i->mlx, FILE_1b, &buf, &buf);
	j = 0;
	while (i->map_c[j])
	{
		if (i->map_c[j] == '1')
			mlx_put_image_to_window(i->mlx, i->win, img1, (j % i->map_w) * BLOCKLEN, (j / i->map_w) * BLOCKLEN);
		else
			mlx_put_image_to_window(i->mlx, i->win, img0, (j % i->map_w) * BLOCKLEN, (j / i->map_w) * BLOCKLEN);
		j++;
	}
	mlx_destroy_image(i->mlx, img0);
	mlx_destroy_image(i->mlx, img1);
	set_win1(i);
	return ;
	
	return ;
}

void	set_win1(t_info	*i)
{
	size_t	j;
	int		buf;
	void	*imgc;
	void	*imge;

	imgc = mlx_xpm_file_to_image(i->mlx, FILE_C, &buf, &buf);
	imge = mlx_xpm_file_to_image(i->mlx, FILE_E, &buf, &buf);
	j = 0;
	while (i->map_c[j])
	{
		if (i->map_c[j] == 'C')
			mlx_put_image_to_window(i->mlx, i->win, imgc, (j % i->map_w) * BLOCKLEN, (j / i->map_w) * BLOCKLEN);
		else if (i->map_c[j] == 'E')
			mlx_put_image_to_window(i->mlx, i->win, imge, (j % i->map_w) * BLOCKLEN, (j / i->map_w) * BLOCKLEN);
		j++;
	}
	mlx_destroy_image(i->mlx, imgc);
	mlx_destroy_image(i->mlx, imge);
	mlx_put_image_to_window(i->mlx, i->win, i->img_p, (i->mc % i->map_w) * BLOCKLEN, (i->mc / i->map_w) * BLOCKLEN);
}

int game_process(void *p)
{
	t_info	*i;

	i = p;
	if (i->time == i->reset)
		i->key_ok = 1;
	if (i->key == NO_KEY && i->newkey != NO_KEY && i->key_ok)
		i->reset = i->time;
	i->key = i->newkey;
	if (i->newkey == ESC_KEY)
		end_game(i);
	else if (i->key != NO_KEY && i->key_ok)
	{
		mlx_put_image_to_window(i->mlx, i->win, i->img_0, (i->mc % i->map_w) * BLOCKLEN, (i->mc / i->map_w) * BLOCKLEN);
		move(i, i->key);
		i->key_ok = 0;
	}
	i->time++;
	i->time &= WEIFHT;
	return (0);
}

int set_gkey(int	key, void	*p)
{
	t_info	*i;

	i = p;
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

void move(t_info	*i, int key)
{
	int	c;

	if (key == RIGHT)
		c = 1;
	else if (key == FRONT)
		c = i->map_w * -1;
	else if (key == LEFT)
		c = -1;
	else
		c = i->map_w;
	if (i->map_c[i->mc + c] != '1'\
		&& i->map_c[i->mc + c] != 'E')
	{
		ft_printf("%u\n", i->walk++);
		i->mc += c;
		if(i->map_c[i->mc] == 'C')
			i->item--;
		i->map_c[i->mc] = '0';
	}
	else if (i->map_c[i->mc + c] == 'E' && !i->item)
		end_game(i);
	mlx_put_image_to_window(i->mlx, i->win, i->img_p, \
	(i->mc % i->map_w) * BLOCKLEN, (i->mc / i->map_w) * BLOCKLEN);
}


int rm_gkey(int	key, void	*p)
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

void	file_error(char *must_free, char *msg)
{
	free(must_free);
	if (msg)
		write(STDOUT_FILENO, msg, ft_strlen(msg));
	exit(1);
}

int		end_game(void *p)
{
	t_info *i;

	i = p;
	mlx_destroy_image(i->mlx, i->img_0);
	mlx_destroy_image(i->mlx, i->img_p);
	mlx_destroy_window(i->mlx, i->win);
	free(i->map_c);
	exit(0);
	return (0);
}
