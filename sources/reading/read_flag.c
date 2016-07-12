/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:17:20 by alegent           #+#    #+#             */
/*   Updated: 2016/07/12 15:08:34 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					read_flag(t_pf *pf, t_nd *nd)
{
	char				*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return ;
	str[1] = 0;
	str[0] = '%';
	if (nd->weight)
	{
		if (!(*str))
			nd->weight--;
		if (!(nd->opt & OPT_MINUS))
			print_weight(pf, nd, &str);
	}
	print_char(pf, str[0]);
	if (nd->weight && nd->opt & OPT_MINUS)
		print_minus_weight(pf, nd->weight - (int)ft_strlen(str));
}
