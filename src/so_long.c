#include"so_long.h"
#include "debug.h"

int g_key;

int main(int argc, char *argv[])
{
	t_info i;

	ft_bzero(&i, sizeof(t_info));
	get_map(&i, argc, argv);
	i.mlx = mlx_init();
	get_img(&i);
	set_win(&i);
	i.win = mlx_new_window(i.mlx, i.map_w * BLOCKLEN, i.map_h * BLOCKLEN, "so_long");
	mlx_loop_hook(i.win, game_process, &i);
	mlx_hook(i.win, 2, 0, set_gkey, NULL);
	mlx_hook(i.win, 3, 0, rm_gkey, NULL);
	mlx_hook(i.win, 17, 0, end_game, NULL);
	mlx_loop(i.mlx);
 return (0);
}

void get_map(t_info *i, int argc, char *argv[])
{
	if (argc < 2)
		error_exit("No map!\n");
	if (argc > 2)
		error_exit("Too many maps!\n");
	if (ft_memcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		error_exit("Invalid format!\n");
	read_map(0, argv[1], 0);
	set_map(&i);
}

void	read_map(t_info	*i, int	fd, char	*name, size_t	s)
{
	char	buf[BUFSIZ]
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
		read_map(i, fd, name, s + j)
	ft_memcpy(i->map_c, buf, i);
	return ;
}

void	set_map(t_info	*i)
{
	size_t	j;
	size_t	c;
	size_t	e;

	j = 0;
	c = 0;
	e = 0;
	while (i->map_c[j] == '1')
		j++;
	if (i->map_c[j] != '\n')
		file_error(i->map_c);
	i->map_w = j;
	i->map_h = 1;
	c = j;
	j++;
	while (i->map_c[j])
	{
		if (!(j % (i->map_w + 1)) && i->map_c[j] != '1'\
			|| !((j + 2) % (i->map_w + 1)) && i->map_c[j] != '1'\
			|| !((j + 1) % (i->map_w + 1)) && i->map_c[j] != '\n'\
			|| i->mc && i->map_c[j] != 'P')
			file_error(i->map_c);
		if (i->map_c[j] == '0' || i->map_c[j] == '1' || i->map_c[j] == 'C' || i->map_c[j] == 'E')
		{
			if (i->map_c[j] == 'C')
				i->item++;
			else if (i->map_c[j] == 'E')
				e++;
			i->map_c[c] = i->map_c[j];
		}
		else if (i->map_c[j] == 'P')
		{
			i->mc = c;
			i->map_c[c] = '0';
		}
		else
			file_error(i->map_c);
		j++;
		if ((j + 1) % (i->map_w + 1))
			c++;
		else
			i->map_h++;
	}
	if (j % (i->map_w + 1) || !(i->mc) || !(i->item) || !e)
		file_error(i->map_c);
	i->map_c[c + 1] = '\0';
	while (c % i->map_w)
	{
		if (i->map_c[c] != '1')
			file_error(i->map_c);
		c--;
	}
	if (i->map_c[c] != '1')
		file_error(i->map_c);
	return ;
}

void	get_img(t_info	*i)
{
	int	buf;

	i->img_0 = mlx_xpm_file_to_image(i->mlx, FILE_0, &buf, &buf);
	i->img_1 = mlx_xpm_file_to_image(i->mlx, FILE_1, &buf, &buf);
	i->img_p = mlx_xpm_file_to_image(i->mlx, FILE_P, &buf, &buf);
	i->img_c = mlx_xpm_file_to_image(i->mlx, FILE_C, &buf, &buf);
	i->img_e = mlx_xpm_file_to_image(i->mlx, FILE_E, &buf, &buf);
	return ;
}

void	set_win(t_info	*i)
{
	char	c;
	size_t	j;

	while (i->map_c[j])
	{
		if (c == '0')
			mlx_put_image_to_window(i->mlx, i->win, i->img_0, (j % i->map_w) * BLOCKLEN, (j % i->map_h) * BLOCKLEN);
		else if (c == '1')
			mlx_put_image_to_window(i->mlx, i->win, i->img_1, (j % i->map_w) * BLOCKLEN, (j % i->map_h) * BLOCKLEN);
		else if (c == 'C')
			mlx_put_image_to_window(i->mlx, i->win, i->img_c, (j % i->map_w) * BLOCKLEN, (j % i->map_h) * BLOCKLEN);
		else if (c == 'E')
			mlx_put_image_to_window(i->mlx, i->win, i->img_e, (j % i->map_w) * BLOCKLEN, (j % i->map_h) * BLOCKLEN);
		j++;
		c = i->map_c[j]
	}
	mlx_put_image_to_window(i->mlx, i->win, i->img_p, (i->mc % i->map_w) * BLOCKLEN, (i->mc % i->map_h) * BLOCKLEN);
	return ;
}

int game_process(void *p)
{
	static	unsigned char time = 0;
	t_info	*i;
	int		key;

	i = p;
	key = g_key;
	if (key == ESC_KEY)
		end_game(i);
	else if (key != NO_KEY && !time)
	{
		mlx_put_image_to_window(i->mlx, i->win, i->img_0, (i->mc % i->map_w) * BLOCKLEN, (i->mc % i->map_h) * BLOCKLEN);
		move(i, key);
	}
	time++;
	return (0);
}

void move(t_info	*i, int key)
[
	int	c;

	if (key == RIGHT)
		c = 1;
	else if (key == FRONT)
		c = i->map_w * -1;
	else if (key == LEFT)
		c = -1;
	else
		c = i->map_w;
	if (i->map_c[i->mc + c] != '1'
		|| i->map_c[i->mc + c] != 'E')
	{
		write(STDOUT_FILENO, "[moveing]\n", 10);
		i->mc += c;
		if(i->map_c[i->mc] == 'C')
			i->item--;
		i->map_c[i->mc] = '0';
	}
	else if (i->map_c[i->mc + c] == 'E' && !i->item)
		end_game(i);
	mlx_put_image_to_window(i->mlx, i->win, i->img_p, (i->mc % i->map_w) * BLOCKLEN, (i->mc % i->map_h) * BLOCKLEN);
]

int set_gkey(int	key, void	*p)
{
	(void)p;
	if (key == 0 || key == 123)
		g_key = LEFT;
	else if (key == 1 || key == 125)
		g_key = BACK;
	else if (key == 2 || key == 124)
		g_key = RIGHT;
	else if (key == 13 || key == 126)
		g_key = FRONT;
	else if (key == 53)
		g_key = ESC_KEY;
	else
		g_key = NO_KEY;
TESTn(g_key)
	return(0);
}

int rm_gkey(int	key, void	*p)
{
	(void)p;
	g_key = NO_KEY;
TEST
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

void	end_game(t_info *i)
{
	mlx_destroy_image(i->mlx, i->img_0);
	mlx_destroy_image(i->mlx, i->img_1);
	mlx_destroy_image(i->mlx, i->img_p);
	mlx_destroy_image(i->mlx, i->img_c);
	mlx_destroy_image(i->mlx, i->img_e);
	mlx_destroy_window(i->mlx, i->win);
	free(i->map_c);
	exit(0);
}
