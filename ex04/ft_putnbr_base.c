/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:56:26 by yrabby            #+#    #+#             */
/*   Updated: 2022/05/24 16:13:10 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define ERROR -1
#define SUCCESS 0

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_base(long n, long base, char *base_test)
{
	if (n / base)
	{
		ft_put_base(n / base, base, base_test);
		ft_put_base(n % base, base, base_test);
	}
	if (n < base)
		ft_putchar(base_test[n]);
}

long	ft_strlen_check(char *s)
{
	long	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-' || s[i] == '+')
			return (ERROR);
		++i;
	}
	return (i);
}

int	get_base(char *s, long *res)
{
	long	i;
	long	j;

	i = 0;
	*res = ft_strlen_check(s);
	if (*res <= 1 || *res == ERROR)
		return (ERROR);
	while (i < *res)
	{
		j = i + 1;
		while (j < *res)
		{
			if (s[i] == s[j])
				return (ERROR);
			++j;
		}
		++i;
	}
	return (SUCCESS);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	long_base;
	long	n;

	n = (long)nbr;
	if (get_base(base, &long_base) == ERROR)
		return ;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	ft_put_base(n, long_base, base);
}
