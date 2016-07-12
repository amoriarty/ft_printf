/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_weight.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:16:56 by alegent           #+#    #+#             */
/*   Updated: 2016/07/12 12:13:33 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				print_precision(t_pf *pf, int len)
{
	int					i;

	i = -1;
	while (++i < len)
		print_char(pf, '0');
}

void					print_weight(t_pf *pf, t_nd *nd, char **str)
{
	int					i;
	int					len;

	i = -1;
	len = (int)ft_strlen(*str);
	if (nd->precision > -1 && nd->precision < len)
		len = nd->precision;
	if (nd->precision > len)
	{
		if (*str[0] == '-')
		{
			print_char(pf, *((*str)++));
			len--;
		}
		print_precision(pf, nd->precision - len);
	}
	if (len >= nd->weight)
		return ;
	while (++i < nd->weight - len)
		print_char(pf, ((nd->opt & OPT_ZERO)) ? '0' : ' ');
}
