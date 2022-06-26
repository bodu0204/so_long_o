#include"so_long.h"

void go_straight(t_info	*i, t_mob *m)
{
	int	c;

	if (m->direct == RIGHT)
		c = 1;
	else if (m->direct == FRONT)
		c = i->map_w * -1;
	else if (m->direct == LEFT)
		c = -1;
	else if(m->direct == BACK)
		c = i->map_w;
	else
		c = 0;
	m->to += c;
	return ;
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
