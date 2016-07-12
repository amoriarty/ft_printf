/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_opt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:15:48 by alegent           #+#    #+#             */
/*   Updated: 2016/07/12 11:15:49 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				get_opt(t_pf *pf, t_nd *nd)
{
	while (isin(OPT, *(pf->format)))
	{
		if (*(pf->format) == '#')
			nd->opt |= OPT_SHARP;
		if (*(pf->format) == '-')
			nd->opt |= OPT_MINUS;
		if (*(pf->format) == ' ')
			nd->opt |= OPT_SPACE;
		if (*(pf->format) == '+')
			nd->opt |= OPT_PLUS;
		if (*(pf->format) == '0')
			nd->opt |= OPT_ZERO;
		pf->format++;
	}
}
