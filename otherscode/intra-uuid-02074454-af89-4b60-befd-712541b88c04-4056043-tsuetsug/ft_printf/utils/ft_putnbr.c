/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:18:35 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/12 14:18:40 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int n)
{	
	int	t;

	t = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		t += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		t += ft_putnbr(n / 10);
	t += ft_putchar(n % 10 + '0');
	return (t);
}

unsigned int	ft_putnbr_u(unsigned int n)
{	
	int	t;

	t = 0;
	if (n > 9)
		t += ft_putnbr(n / 10);
	t += ft_putchar(n % 10 + '0');
	return (t);
}
