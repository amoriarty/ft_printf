/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_modifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:15:43 by alegent           #+#    #+#             */
/*   Updated: 2016/07/12 11:15:44 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			get_mod_h(t_pf *pf, t_nd *nd)
{
	if (*(pf->format) == 'h')
	{
		pf->format++;
		if (*(pf->format) == 'h')
		{
			nd->opt |= MOD_HH;
			pf->format++;
		}
		else
			nd->opt |= MOD_H;
	}
}

static void			get_mod_l(t_pf *pf, t_nd *nd)
{
	if (*(pf->format) == 'l')
	{
		pf->format++;
		if (*(pf->format) == 'l')
		{
			nd->opt |= MOD_LL;
			pf->format++;
		}
		else
			nd->opt |= MOD_L;
	}
}

void				get_modifier(t_pf *pf, t_nd *nd)
{
	while (isin(MODIF, *(pf->format)))
	{
		get_mod_h(pf, nd);
		get_mod_l(pf, nd);
		if (*(pf->format) == 'j')
		{
			nd->opt |= MOD_J;
			pf->format++;
		}
		if (*(pf->format) == 'z')
		{
			nd->opt |= MOD_Z;
			pf->format++;
		}
	}
}
