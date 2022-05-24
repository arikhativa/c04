/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:45:50 by yrabby            #+#    #+#             */
/*   Updated: 2022/05/24 11:45:52 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	count_digit(int n)
{
	int	c;

	c = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		++c;
	}
	return (c);
}

int	power(int n, int p)
{
	int	ret;

	ret = n;
	if (p == 0)
		return (1);
	while (p > 1)
	{
		ret *= n;
		--p;
	}
	return (ret);
}

void	ft_putnbr(int nb)
{
	int		p;
	char	ch;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = nb * -1;
		write(1, "-", 1);
	}
	p = power(10, count_digit(nb) - 1);
	while (p)
	{
		ch = (nb / p) + '0';
		write(1, &ch, 1);
		nb %= p;
		p /= 10;
	}
}
