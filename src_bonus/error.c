#include"so_long.h"

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
	if (i->situ != END)
		frree_content(i);
	mlx_destroy_window(i->mlx, i->win);
	exit(1);
	return (0);
}

void	free_Wmob_error(t_info	*i)
{
	t_mob	*m;

	while(i->mw)
	{
		m = i->mw;
		i->mw = i->mw->next;
		free(m);
	}
	file_error(i->map_c);
	return ;
}
