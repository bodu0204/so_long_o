/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:17:41 by ryoakira          #+#    #+#             */
/*   Updated: 2022/06/26 20:51:09 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	check_arg(int argc, char *argv[])
{
	if (argc < 2)
		error_exit("No map!\n");
	if (argc > 2)
		error_exit("Too many maps!\n");
	if (ft_strlen(argv[1]) < 4)
		error_exit("Invalid format!\n");
	if (ft_memcmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4))
		error_exit("Invalid format!\n");
	return ;
}

int	is_map_elem(char elm, size_t c, size_t	w, size_t	h)
{
	if ((c % w == 0 && elm != '1') \
	|| (c % w == w - 1 && elm != '1') \
	|| (c < w - 1 && elm != '1') \
	|| (c > w * (h - 1) && elm != '1') \
	|| (elm != '0' && elm != '1' && elm != 'E' && elm != 'C' \
		&& elm != 'P'))
		return (1);
	return (0);
}
