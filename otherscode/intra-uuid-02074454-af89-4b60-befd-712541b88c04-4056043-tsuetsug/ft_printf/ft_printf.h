/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsuetsug <tsuetsug@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:15:36 by tsuetsug          #+#    #+#             */
/*   Updated: 2022/03/12 14:15:38 by tsuetsug         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *str, ...);
int				ft_putnbr_base(unsigned int nbr, char *base);
int				ft_putnbr(int n);
int				ft_putstr(char *s);
int				ft_putchar(char c);
int				ft_putmemory(unsigned long long *t, char *table);
unsigned int	ft_putnbr_u(unsigned int n);

#endif