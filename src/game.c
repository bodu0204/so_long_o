#include"so_long.h"

int	game_process(void *p)
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
		mlx_put_image_to_window(i->mlx, i->win, i->img_0, \
		(i->mc % i->map_w) * BLOCKLEN, (i->mc / i->map_w) * BLOCKLEN);
		move(i, i->key);
		i->key_ok = 0;
	}
	i->time++;
	i->time &= WEIFHT;
	return (0);
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
