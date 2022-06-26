/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:19:30 by ryoakira          #+#    #+#             */
/*   Updated: 2022/06/26 20:19:31 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

int	is_map_elem(char elm, size_t c, size_t	w, size_t	h)
{
	if ((c % w == 0 && elm != '1') \
	|| (c % w == w - 1 && elm != '1') \
	|| (c < w - 1 && elm != '1') \
	|| (c > w * (h - 1) && elm != '1') \
	|| (elm != '0' && elm != '1' && elm != 'E' && elm != 'C' \
		&& elm != 'P' && elm != 'W' && elm != 'M' && elm != 'F'))
		return (1);
	return (0);
}

void	set_mob(t_info	*i)
{
	size_t	j;

	j = 0;
	while (i->map_c[j])
	{
		if (i->map_c[j] == 'P')
			reset_mob(i, &(i->mp), j, BACK);
		else if (i->map_c[j] == 'M')
			i->mm = j;
		else if (i->map_c[j] == 'F')
			i->mf = j;
		else if (i->map_c[j] == 'W')
			set_Wmob(i, j);
		j++;
	}
	return ;
}

void	reset_mob(t_info	*i, t_mob *m, size_t c, int d)
{
	m->to = c;
	m->nowx = (c % i->map_w) * BLOCKLEN;
	m->nowy = (c / i->map_w) * BLOCKLEN;
	if (m->direct < 4)
		m->direct = d % 4;
	return ;
}

void	set_Wmob(t_info	*i, size_t c)
{
	t_mob	*new;
	t_mob	*last;

	new = malloc(sizeof(t_mob));
	if (!new)
		free_Wmob_error(i);
	new->next = NULL;
	reset_mob(i, new, c, my_rand(i->buf));
	last = i->mw;
	if (!last)
		i->mw = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
	return ;
}
