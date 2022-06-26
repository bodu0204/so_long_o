/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_win_util_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:19:06 by ryoakira          #+#    #+#             */
/*   Updated: 2022/06/26 20:19:07 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"
size_t	f_presence1(t_info	*i, t_mob *m, size_t	fp);
size_t	f_presence2(size_t	r);

size_t	f_presence(t_info	*i, t_mob *m)
{
	size_t	fx;
	size_t	fy;

	if (!i->mf)
		return (f_presence1(i, m, 5 * BLOCKLEN));
	fx = (i->mf % i->map_w) * BLOCKLEN;
	fy = (i->mf / i->map_w) * BLOCKLEN;
	if (fx < i->mp.nowx)
		fx = i->mp.nowx - fx;
	else
		fx -= i->mp.nowx;
	if (fy < i->mp.nowy)
		fy = i->mp.nowy - fy;
	else
		fy -= i->mp.nowy;
	if (fy > fx)
		fx = fy;
	return (f_presence1(i, m, fx));
}

size_t	f_presence1(t_info	*i, t_mob *m, size_t	fp)
{
	size_t	fx;
	size_t	fy;

	fx = i->mp.nowx;
	fy = i->mp.nowy;
	if (fx < m->nowx)
		fx = m->nowx - fx;
	else
		fx -= m->nowx;
	if (fy < m->nowy)
		fy = m->nowy - fy;
	else
		fy -= m->nowy;
	if (fy > fx)
		fx = fy;
	if (!fx)
		fx = 1;
	if ((fp / BLOCKLEN) > 5)
		fp = 1;
	else
		fp = 5 - (fp / BLOCKLEN) + 1;
	fy = (16 * fp * BLOCKLEN) / fx;
	return (f_presence2(fy));
}

size_t	f_presence2(size_t	r)
{
	if (r < 7)
		return (0);
	else if (r > 16)
		return (9);
	return (r - 7);
}
