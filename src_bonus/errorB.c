#include"so_long.h"
void	frree_content1(t_info *i);

void	frree_content(t_info *i)
{
	mlx_destroy_image(i->mlx, i->img_0);
	mlx_destroy_image(i->mlx, i->img_p[FRONT]);
	mlx_destroy_image(i->mlx, i->img_p[BACK]);
	mlx_destroy_image(i->mlx, i->img_p[LEFT]);
	mlx_destroy_image(i->mlx, i->img_p[RIGHT]);
	mlx_destroy_image(i->mlx, i->img_c);
	mlx_destroy_image(i->mlx, i->img_e);
	mlx_destroy_image(i->mlx, i->img_w[1]);
	mlx_destroy_image(i->mlx, i->img_w[2]);
	mlx_destroy_image(i->mlx, i->img_w[3]);
	mlx_destroy_image(i->mlx, i->img_w[4]);
	mlx_destroy_image(i->mlx, i->img_w[5]);
	mlx_destroy_image(i->mlx, i->img_w[6]);
	mlx_destroy_image(i->mlx, i->img_w[7]);
	mlx_destroy_image(i->mlx, i->img_w[8]);
	mlx_destroy_image(i->mlx, i->img_w[9]);
	mlx_destroy_image(i->mlx, i->img_w[10]);
	frree_content1(i);
	return ;
}

void	frree_content1(t_info *i)
{
	t_mob	*m;

	free(i->map_c);
	m = i->mw;
	while (m)
	{
		free(m);
		m = m->next;
	}
	return ;
}
