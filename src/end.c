/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:17:22 by ryoakira          #+#    #+#             */
/*   Updated: 2022/06/26 20:17:23 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	error_exit(char *msg)
{
	if (msg)
		write(STDOUT_FILENO, msg, ft_strlen(msg));
	exit(1);
	return ;
}

void	file_error(char *must_free, char *msg)
{
	free(must_free);
	if (msg)
		write(STDOUT_FILENO, msg, ft_strlen(msg));
	exit(1);
}

int	end_game(void *p)
{
	t_info	*i;

	i = p;
	mlx_destroy_image(i->mlx, i->img_0);
	mlx_destroy_image(i->mlx, i->img_p);
	mlx_destroy_window(i->mlx, i->win);
	free(i->map_c);
	exit(0);
	return (0);
}
