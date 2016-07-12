/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_octal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:17:52 by alegent           #+#    #+#             */
/*   Updated: 2016/07/12 11:34:38 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*read_long(t_pf *pf)
{
	long				value;
	char				*str;

	value = va_arg(pf->ap, long);
	str = itoa_base_long(value, 8);
	return (str);
}

static char				*read_long_long(t_pf *pf)
{
	long long			value;
	char				*str;

	value = va_arg(pf->ap, long long);
	str = itoa_base_long_long(value, 8);
	return (str);
}

void					read_octal(t_pf *pf, t_nd *nd)
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
		str = uitoa_base(value, 8);
	}
	if (nd->opt & OPT_SHARP && str[0] != '0')
	{
		print_char(pf, '0');
		nd->weight--;
	}
	if ((nd->weight || nd->precision > -1) && !(nd->opt & OPT_MINUS))
		print_weight(pf, nd, &str);
	if (!(nd->precision) && str[0] == '0')
		return ;
	print_str(pf, str);
	if (nd->weight && nd->opt & OPT_MINUS)
		print_minus_weight(pf, nd->weight - (int)ft_strlen(str));
}
