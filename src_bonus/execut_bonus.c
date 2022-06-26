/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:18:48 by ryoakira          #+#    #+#             */
/*   Updated: 2022/06/26 20:18:49 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	move(t_info	*i)
{
	t_mob	*m;

	clean_win(i);
	move_mob(i, &(i->mp));
	m = i->mw;
	while (m)
	{
		move_mob(i, m);
		m = m->next;
	}
	move_result(i);
	e_win(i);
	p_win(i);
	w_win(i);
	c_win(i);
	return ;
}

void	clean_win(t_info	*i)
{
	t_mob	*m;

	mlx_put_image_to_window(i->mlx, i->win, i->img_0, i->mp.nowx, i->mp.nowy);
	m = i->mw;
	while (m)
	{
		mlx_put_image_to_window(i->mlx, i->win, i->img_0, m->nowx, m->nowy);
		m = m->next;
	}
	return ;
}

void	move_mob(t_info	*i, t_mob	*m)
{
	if (m->direct == NO_KEY || m->direct >= DEAD \
	|| ((m->to % i->map_w) * BLOCKLEN == m->nowx \
		&& (m->to / i->map_w) * BLOCKLEN == m->nowy))
	{
		if (m->direct >= DEAD)
			m->direct++;
		return ;
	}
	if (m->direct == FRONT)
		m->nowy--;
	else if (m->direct == RIGHT)
		m->nowx++;
	else if (m->direct == BACK)
		m->nowy++;
	else if (m->direct == LEFT)
		m->nowx--;
	return ;
}

void	move_result(t_info	*i)
{
	t_mob	*m;

	i->mw = rm_w(i->mw);
	m = i->mw;
	while (m)
	{
		m_killer(i, m);
		m = m->next;
	}
	m = i->mw;
	while (m)
	{
		if (m->direct < DEAD && distance(m, &(i->mp)) < DEATHLEN \
		&& i->situ != SUCCESS)
		{
			i->situ = FALE;
			break ;
		}
		m = m->next;
	}
	return ;
}

t_mob	*rm_w(t_mob *start)
{
	t_mob	*m;
	t_mob	*mn;

	if (!start)
		return (NULL);
	m = start;
	while (m->next)
	{
		if (m->next->direct >= DEAD + BLOCKLEN)
		{
			mn = m->next;
			m->next = mn->next;
			free(mn);
		}
		else
			m = m->next;
	}
	if (start->direct >= DEAD + BLOCKLEN)
	{
		m = start->next;
		free(start);
		return (m);
	}
	return (start);
}
