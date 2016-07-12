/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:15:00 by alegent           #+#    #+#             */
/*   Updated: 2016/07/12 11:15:02 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void					rapid_swap(char **res, char **tmp)
{
	char					*swap;

	swap = NULL;
	swap = ft_strdup(*res);
	*res = ft_strjoin(*tmp, swap);
}

char						*itoa_base_long(long nbr, int base)
{
	int						value;
	int						rest;
	char					*res;
	char					*tmp;

	res = NULL;
	tmp = ft_strnew(1);
	value = 1;
	while (value)
	{
		value = nbr / base;
		rest = nbr % base;
		nbr = value;
		if ((rest >= 0) && (rest <= 9))
			tmp[0] = rest + 48;
		else
			tmp[0] = rest + 87;
		if (res)
			rapid_swap(&res, &tmp);
		else
			res = ft_strdup(tmp);
	}
	return (res);
}
