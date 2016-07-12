/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:17:13 by alegent           #+#    #+#             */
/*   Updated: 2016/07/12 11:35:22 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					read_char(t_pf *pf, t_nd *nd)
{
	char				*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return ;
	str[1] = 0;
	str[0] = (char)va_arg(pf->ap, int);
	if (nd->weight)
	{
		if (!(*str) && !(nd->opt & OPT_MINUS))
			nd->weight--;
		if (!(nd->opt & OPT_MINUS))
			print_weight(pf, nd, &str);
	}
	print_char(pf, str[0]);
	if (nd->opt & OPT_MINUS)
		print_minus_weight(pf, nd->weight - 1);
}
