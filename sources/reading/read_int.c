/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:17:37 by alegent           #+#    #+#             */
/*   Updated: 2016/07/12 11:37:24 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*read_long(t_pf *pf)
{
	long				value;
	char				*str;

	value = va_arg(pf->ap, long);
	str = itoa_base_long(value, 10);
	return (str);
}

static char				*read_long_long(t_pf *pf)
{
	long long			value;
	char				*str;

	value = va_arg(pf->ap, long long);
	str = itoa_base_long_long(value, 10);
	return (str);
}

static void				ft_norme(t_pf *pf, t_nd *nd, char *str)
{
	if (nd->opt & OPT_PLUS && str[0] != '-')
	{
		print_char(pf, '+');
		nd->weight--;
	}
	else if (nd->opt & OPT_SPACE && str[0] != '-')
		print_char(pf, ' ');
}

void					read_int(t_pf *pf, t_nd *nd)
{
	int					value;
	char				*str;

	if (nd->opt & MOD_L)
		str = read_long(pf);
	else if (nd->opt & MOD_LL)
		str = read_long_long(pf);
	else
	{
		value = va_arg(pf->ap, int);
		str = ft_itoa(value);
	}
	ft_norme(pf, nd, str);
	if (str[0] == '-' && nd->opt & OPT_ZERO)
	{
		print_char(pf, *(str++));
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
