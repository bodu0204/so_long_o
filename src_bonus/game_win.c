#include"so_long.h"

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
			if (m->direct % 8 < 4)
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
