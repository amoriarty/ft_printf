/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:17:07 by alegent           #+#    #+#             */
/*   Updated: 2016/07/12 11:41:52 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*read_long(t_pf *pf)
{
	unsigned long		value;
	char				*str;

	value = va_arg(pf->ap, unsigned long);
	str = uitoa_base_long(value, 2);
	return (str);
}

static char				*read_long_long(t_pf *pf)
{
	unsigned long long	value;
	char				*str;

	value = va_arg(pf->ap, unsigned long long);
	str = uitoa_base_long_long(value, 2);
	return (str);
}

void					read_binary(t_pf *pf, t_nd *nd)
{
	unsigned int		value;
	char				*str;

	if (nd->opt & MOD_L)
		str = read_long(pf);
	else if (nd->opt & MOD_LL)
		str = read_long_long(pf);
	else
	{
		value = va_arg(pf->ap, unsigned int);
		str = uitoa_base(value, 2);
	}
	if (nd->weight)
		print_weight(pf, nd, &str);
	print_str(pf, str);
}
