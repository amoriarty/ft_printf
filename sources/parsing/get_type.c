/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:16:00 by alegent           #+#    #+#             */
/*   Updated: 2016/07/12 14:02:44 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void				ft_norme(t_pf *pf, t_nd *nd)
{
	nd->opt |= INT;
	if (*(pf->format) == 'd' || *(pf->format) == 'D' || *(pf->format) == 'i')
	{
		nd->opt |= SIGNED;
		nd->opt |= DEC;
		if (*(pf->format) == 'D')
			nd->opt |= MOD_L;
	}
}

static void				get_integer(t_pf *pf, t_nd *nd)
{
	ft_norme(pf, nd);
	if (*(pf->format) == 'o' || *(pf->format) == 'O')
	{
		nd->opt |= OCTAL;
		if (*(pf->format) == '0')
			nd->opt |= MOD_L;
	}
	if (*(pf->format) == 'u' || *(pf->format) == 'U')
	{
		nd->opt |= DEC;
		if (*(pf->format) == 'U')
			nd->opt |= MOD_L;
	}
	if (*(pf->format) == 'x' || *(pf->format) == 'X')
	{
		nd->opt |= HEXA;
		if (*(pf->format) == 'X')
			nd->opt |= MAJ;
	}
	if (*(pf->format) == 'b')
		nd->opt |= BINARY;
}

void					get_type(t_pf *pf, t_nd *nd)
{
	if (*(pf->format) == 'c' || *(pf->format) == 'C')
		nd->opt |= CHAR;
	if (*(pf->format) == 's' || *(pf->format) == 'S')
		nd->opt |= STR;
	if (*(pf->format) == 'C' || *(pf->format) == 'S')
		nd->opt |= WIDE;
	if (*(pf->format) == 'p')
		nd->opt |= POINTER;
	if (isin(INTERGER, *(pf->format)))
		get_integer(pf, nd);
	if (*(pf->format) == FLAG)
		nd->opt |= T_FLAG;
	pf->format++;
}
