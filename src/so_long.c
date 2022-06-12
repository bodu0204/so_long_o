#include"so_long.h"
#include "debug.h"

int g_key;

int main(int argc, char *argv[])
{
	t_info i;

	//get_map(&i, argc, argv);
	//get_img(&i);
	i.mlx = mlx_init();
	i.win = mlx_new_window(i.mlx, /* i.map_w * */ BLOCKLEN, /* i.map_h *  */BLOCKLEN, "so_long");
	//mlx_loop_hook(i.win, game_process, &i);
	mlx_hook(i.win, 2, 0, set_gkey, NULL);
	mlx_hook(i.win, 3, 0, rm_gkey, NULL);
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
	if (set_map(&i, read_map(0, argv[1], 0)))
		error_exit("Unreadable file\n");
}

char	*read_map(int	fd, char *name, size_t s)
{
	char	buf[BUFSIZ]
	ssize_t	i;
	char	*r;

	if (fd == 0 && name)
	{
		fd = open(name, O_RDONLY);
		if (fd < 0)
			error_exit("Unreadable file\n");
	}
	i = read(fd, buf, BUFSIZ);
	if (i < 0)
		error_exit("Read error\n");
	if (i == 0)
	{
		close(fd);
		r = malloc(s + i + 1);
		if (!r)
			error_exit("malloc errror\n");
		r[s + i] = '\0';
	}
	else
		r = read_map(fd, name, s + i)
	ft_memcpy(r, buf, i);
	return (r);
}

int game_process(void *p)
{
	t_info	*i;
	i = p;

	return (0);
}

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