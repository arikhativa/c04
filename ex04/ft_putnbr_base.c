/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:56:26 by yrabby            #+#    #+#             */
/*   Updated: 2022/05/24 15:36:10 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define DECIMAL "0123456789"
#define BINARY "01"
#define OCTAL "poneyvif"
#define HEX "0123456789ABCDEF"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_base(long n, long base)
{
	if (n / base)
	{
		ft_put_base(n / base, base);
		ft_put_base(n % base, base);
	}
	if (n < base)
	{
		if (n < 10)
			ft_putchar(n + '0');
		else if (n < 16)
			ft_putchar(n + 'A' - 10);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	while (*s1 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return (*s1 - *s2);
}

int	get_base(char *s, long *res)
{
	*res = -1;
	if (!ft_strcmp(s, DECIMAL))
		*res = 10;
	else if (!ft_strcmp(s, BINARY))
		*res = 2;
	else if (!ft_strcmp(s, OCTAL))
		*res = 8;
	else if (!ft_strcmp(s, HEX))
		*res = 16;
	return (*res != -1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	int_base;
	long	n;

	n = (long)nbr;
	if (!get_base(base, &int_base))
		return ;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	ft_put_base(n, int_base);
}
