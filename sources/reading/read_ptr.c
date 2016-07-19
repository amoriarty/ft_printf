/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:17:59 by alegent           #+#    #+#             */
/*   Updated: 2016/07/12 12:07:26 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*read_long_long(t_pf *pf)
{
	unsigned long long	value;
	char				*str;

	value = va_arg(pf->ap, unsigned long long);
	str = uitoa_base_long_long(value, 16);
	return (str);
}

static void				ft_norme(t_pf *pf, t_nd *nd, char **str)
{
	if (!(nd->weight))
		print_str(pf, "0x");
	if (nd->precision < (int)ft_strlen(*str) && *str[0] != '0')
		nd->precision = (int)ft_strlen(*str);
	if (nd->weight && nd->opt & OPT_ZERO)
		print_str(pf, "0x");
	if ((nd->weight || nd->precision > -1)
		&& ft_strcmp(*str, "ffffffffffffffff") && !(nd->opt & OPT_MINUS))
		print_weight(pf, nd, str);
	if (nd->weight && !(nd->opt & OPT_ZERO))
		print_str(pf, "0x");
}

void					read_ptr(t_pf *pf, t_nd *nd)
{
	unsigned long		value;
	char				*str;

	if (nd->opt & MOD_LL)
		str = read_long_long(pf);
	else
	{
		value = (unsigned long)va_arg(pf->ap, void *);
		str = uitoa_base_long(value, 16);
	}
	nd->weight -= (nd->weight - 2 >= 0) ? 2 : 0;
	ft_norme(pf, nd, &str);
	if (nd->precision > -1 && nd->precision < (int)ft_strlen(str)
		&& ft_strcmp(str, "ffffffffffffffff"))
		print_n_char(pf, str, nd->precision);
	else
		print_str(pf, str);
	if (nd->weight && nd->opt & OPT_MINUS)
		print_minus_weight(pf, nd->weight - (int)ft_strlen(str));
}
