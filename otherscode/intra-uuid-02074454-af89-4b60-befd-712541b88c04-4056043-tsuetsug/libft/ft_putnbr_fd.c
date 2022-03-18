/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug < tsuetsug@student.42tokyo.jp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 22:01:30 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/01/28 11:15:35 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_minus(int n)
{
	if (n < 0)
		return (-1);
	else
		return (0);
}

int	ft_to_plus(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		minus;
	int		len;
	char	str[13];

	minus = check_minus(n);
	ft_bzero(str, 13);
	if (n == 0)
		str[0] = '0';
	len = 0;
	while (n)
	{
		str[len++] = '0' + ft_to_plus(n % 10);
		n = (n / 10);
	}
	if (minus == -1)
		str[len] = '-';
	else if (len > 0)
		len--;
	while (len >= 0)
		write(fd, &str[len--], 1);
}
