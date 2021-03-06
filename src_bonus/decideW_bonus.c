/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decideW_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:18:28 by ryoakira          #+#    #+#             */
/*   Updated: 2022/06/26 20:18:29 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"
void	next_direct1(t_info	*i, t_mob	*m, int *able);

void	turnw(t_info	*i)
{
	t_mob	*m;

	m = i->mw;
	while (m)
	{
		Wmob(i, m);
		m = m->next;
	}
	return ;
}

void	Wmob(t_info *i, t_mob *m)
{
	int	able[4];

	reset_mob(i, m, m->to, m->direct);
	advance(i, m, able);
	next_direct(i, m, able);
	go_straight(i, m);
	return ;
}

void	next_direct(t_info	*i, t_mob *m, int *able)
{
	if (m->direct >= 4)
		return ;
	if (able[m->direct])
	{
		if ((able[(m->direct + 3) % 4] || able[(m->direct + 1) % 4]) \
		&& my_rand(i->buf) % 2)
		{
			if (able[(m->direct + 3) % 4])
			{
				if (able[(m->direct + 1) % 4] && my_rand(i->buf) % 2)
					m->direct = (m->direct + 1) % 4;
				else
					m->direct = (m->direct + 3) % 4;
			}
			else
				m->direct = (m->direct + 1) % 4;
		}
		else
			m->direct = m->direct;
	}
	else
		next_direct1(i, m, able);
	return ;
}

void	next_direct1(t_info	*i, t_mob	*m, int *able)
{
	if (able[(m->direct + 3) % 4] || able[(m->direct + 1) % 4])
	{
		if (able[(m->direct + 3) % 4])
		{
			if (able[(m->direct + 1) % 4] && my_rand(i->buf) % 2)
				m->direct = (m->direct + 1) % 4;
			else
				m->direct = (m->direct + 3) % 4;
		}
		else
			m->direct = (m->direct + 1) % 4;
	}
	else if (able[(m->direct + 2) % 4])
		m->direct = (m->direct + 2) % 4;
	else
		m->direct = NO_KEY;
	return ;
}
