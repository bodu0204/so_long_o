/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:19:47 by ryoakira          #+#    #+#             */
/*   Updated: 2022/06/26 20:19:48 by ryoakira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

int	my_rand(u_int8_t *base)
{
	int	r;

	base[0] &= 0x7;
	if (!base[0])
	{
		sha256(base + 1, 32, base + 1);
		base[0] = 0;
	}
	ft_memcpy(&r, base + 1 + base[0], sizeof(int));
	if (r < 0)
		r = (r + 1) * -1;
	base[0]++;
	return (r);
}

void	itosu(char	*str, unsigned int	n)
{
	char			*num;
	unsigned int	nn;
	int				i;

	if (n == 0)
	{
		*str = '0';
		return ;
	}
	num = "0123456789";
	nn = 1;
	while (n / nn >= 10)
		nn *= 10;
	while (nn > 0)
	{
		i = n / nn;
		*str = *(num + i);
		str++;
		n -= i * nn;
		nn /= 10;
	}
	*str = '\0';
	return ;
}
