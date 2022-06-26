#include"so_long_bonus.h"

void	turnp(t_info	*i, int key)
{
	int		able[4];
	char	num[32];

	if (key < 4)
		reset_mob(i, &(i->mp), i->mp.to, key);
	else
		reset_mob(i, &(i->mp), i->mp.to, i->mp.direct);
	item_get(i);
	advance(i, &(i->mp), able);
	if (able[key] && key < 4)
	{
		i->walk++;
		itosu(num, i->walk);
		mlx_put_image_to_window(i->mlx, i->win, i->img_1, 0 * BLOCKLEN, 0);
		mlx_put_image_to_window(i->mlx, i->win, i->img_1, 1 * BLOCKLEN, 0);
		mlx_put_image_to_window(i->mlx, i->win, i->img_1, 2 * BLOCKLEN, 0);
		mlx_put_image_to_window(i->mlx, i->win, i->img_1, 3 * BLOCKLEN, 0);
		mlx_string_put(i->mlx, i->win, 0, 12, 0xFFECE1, num);
		go_straight(i, &(i->mp));
	}
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
