/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:18:07 by alegent           #+#    #+#             */
/*   Updated: 2016/07/12 11:31:38 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					read_str(t_pf *pf, t_nd *nd)
{
	char				*str;

	if (nd->opt & WIDE)
		return ;
	str = va_arg(pf->ap, char *);
	if (!str)
		str = ft_strdup("(null)");
	if (nd->weight && !(nd->opt & OPT_MINUS))
		print_weight(pf, nd, &str);
	if (nd->precision > -1 && nd->precision < (int)ft_strlen(str))
		print_n_char(pf, str, nd->precision);
	else
		print_str(pf, str);
	if (nd->weight && nd->opt & OPT_MINUS)
		print_minus_weight(pf, nd->weight - (int)ft_strlen(str));
}
