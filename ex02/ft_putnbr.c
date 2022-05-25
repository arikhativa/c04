/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:45:50 by yrabby            #+#    #+#             */
/*   Updated: 2022/05/25 10:06:11 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print(long n)
{
	if (n / 10)
	{
		print(n / 10);
		print(n % 10);
	}
	if (n < 10)
		ft_putchar(n + '0');
}

void	ft_putnbr(int nb)
{
	long	n;

	n = (long)nb;
	if (n < 0)
	{
		n = n * -1;
		write(1, "-", 1);
	}
	print(n);
}
