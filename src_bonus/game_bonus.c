/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:18:56 by ryoakira          #+#    #+#             */
/*   Updated: 2022/06/26 20:18:57 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

int	game_main(void *p)
{
	t_info	*i;

	i = p;
	if (i->situ == START && i->newkey != NO_KEY)
		i->situ = GAME;
	else if (i->situ == GAME)
		game_process(i);
	else if (i->situ == SUCCESS)
	{
		success_win(i);
		i->situ = END;
	}
	else if (i->situ == FALE)
	{
		fale_win(i);
		i->situ = END;
	}
	else if (i->situ == END && i->newkey == ESC_KEY)
	{
		mlx_destroy_window(i->mlx, i->win);
		exit(0);
	}
	return (0);
}

void	game_process(t_info	*i)
{
	if (!(i->time))
		turnw(i);
	if (i->time == i->reset)
		i->key_ok = 1;
	if (i->key == NO_KEY && i->newkey != NO_KEY && i->key_ok)
		i->reset = i->time;
	i->key = i->newkey;
	if (i->key == ESC_KEY)
		end_game(i);
	else if (i->time == i->reset)
	{
		turnp(i, i->key);
		if (i->key != NO_KEY)
			i->key_ok = 0;
	}
	if (!(i->time % TURN))
		move(i);
	i->time++;
	i->time &= WEIFHT;
	return ;
}
