#include"so_long.h"

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

int	end_game(void *p)
{
	t_info	*i;

	i = p;
	if (i->situ != END)
		frree_content(i);
	mlx_destroy_window(i->mlx, i->win);
	exit(1);
	return (0);
}

void	free_Wmob_error(t_info	*i)
{
	t_mob	*m;

	while (i->mw)
	{
		m = i->mw;
		i->mw = i->mw->next;
		free(m);
	}
	file_error(i->map_c, "W malloc error\n");
	return ;
}
