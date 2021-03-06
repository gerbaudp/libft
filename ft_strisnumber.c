/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgerbaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 11:52:08 by pgerbaud          #+#    #+#             */
/*   Updated: 2018/02/14 13:52:59 by pgerbaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisnumber(char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (-1);
	if (ft_strchr("-+", str[0]) && ft_strlen(str) < 2)
		return (0);
	while (i < (int)ft_strlen(str))
	{
		if ((*(str + i) < 47 || *(str + i) > 58)
				&& *(str + i) != ' ' &&
				!((*(str + i) == '+' || *(str + i) == '-')
					&& (*(str + i - 1) == ' ' || i == 0)))
			return (0);
		i++;
	}
	return (1);
}
