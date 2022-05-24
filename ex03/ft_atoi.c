/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:51:41 by yrabby            #+#    #+#             */
/*   Updated: 2022/05/24 12:15:24 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || \
			c == '\f' || c == '\r' || c == ' ');
}

char	*skip_space(char *s)
{
	while (is_space(*s))
		++s;
	return (s);
}

char	*skip_get_sign(char *s, int *sign)
{
	*sign = 1;
	while (*s == '-' || *s == '+')
	{
		if (*s == '-')
			*sign *= -1;
		++s;
	}
	return (s);
}

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	int	ret;
	int	sign;

	ret = 0;
	str = skip_space(str);
	str = skip_get_sign(str, &sign);
	while (is_num(*str))
	{
		ret = (ret * 10) + (*str - '0');
		++str;
	}
	return (ret * sign);
}
