#include"so_long.h"
void m_killer1(t_info	*i, t_mob	*m);

void m_killer(t_info	*i, t_mob	*m)
{
	size_t	mx;
	size_t	my;

	if (!i->mm || m->direct >= DEAD)
		return ;
	mx = (i->mm % i->map_w) * BLOCKLEN;
	my = (i->mm / i->map_w) * BLOCKLEN;
	if (mx < i->mp.nowx)
		mx = i->mp.nowx - mx;
	else
		mx -= i->mp.nowx;
	if (my < i->mp.nowy)
		my = i->mp.nowy - my;
	else
		my -= i->mp.nowy;
	if (my > mx)
		mx = my;
	if (mx > BLOCKLEN)
		return;
	else
		m_killer1(i, m);
	return ;
}

void m_killer1(t_info	*i, t_mob	*m)
{
	size_t	mx;
	size_t	my;

	mx = (i->mm % i->map_w) * BLOCKLEN;
	my = (i->mm / i->map_w) * BLOCKLEN;
	if (mx < m->nowx)
		mx = m->nowx - mx;
	else
		mx -= m->nowx;
	if (my < m->nowy)
		my = m->nowy - my;
	else
		my -= m->nowy;
	if (my > mx)
		mx = my;
	if (mx <= BLOCKLEN)
		m->direct = DEAD;
	return;
}

size_t distance(t_mob	*m1, t_mob	*m2)
{
	size_t	x;
	size_t	y;

	if (m1->nowx > m2->nowx)
		x = m1->nowx - m2->nowx;
	else
		x = m2->nowx - m1->nowx;
	if (m1->nowy > m2->nowy)
		y = m1->nowy - m2->nowy;
	else
		y = m2->nowy - m1->nowy;
	if (x > y)
		return (x);
	return (y);
}
