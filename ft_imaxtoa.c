/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 18:18:57 by pgerbaud          #+#    #+#             */
/*   Updated: 2017/11/21 16:54:52 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static intmax_t		st_getlength(intmax_t n)
{
	if (n < 0)
		return (st_getlength(-n) + 1);
	if (n > 9)
		return (st_getlength(n / 10) + 1);
	return (1);
}

char				*ft_imaxtoa(intmax_t n)
{
	char		*str;
	int			length;

	if (n == (-9223372036854775807 - 1))
		return (ft_strdup("-9223372036854775808"));
	length = st_getlength(n);
	str = (char *)malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		*str = '-';
		n = -n;
	}
	if (n == 0)
		*str = '0';
	*(str + length--) = '\0';
	while (n > 0)
	{
		*(str + length--) = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
