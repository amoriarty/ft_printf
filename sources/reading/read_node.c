/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:17:43 by alegent           #+#    #+#             */
/*   Updated: 2016/07/12 11:17:44 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					read_node(t_pf *pf, t_nd nd)
{
	if (nd.opt & STR)
		read_str(pf, &nd);
	else if (nd.opt & CHAR)
		read_char(pf, &nd);
	else if (nd.opt & OCTAL)
		read_octal(pf, &nd);
	else if (nd.opt & HEXA)
		read_hexa(pf, &nd);
	else if (nd.opt & POINTER)
		read_ptr(pf, &nd);
	else if (nd.opt & BINARY)
		read_binary(pf, &nd);
	else if (nd.opt & INT && nd.opt & SIGNED)
		read_int(pf, &nd);
	else if (nd.opt & INT)
		read_uint(pf, &nd);
	else if (nd.opt & T_FLAG)
		read_flag(pf, &nd);
	else
		pf->format--;
}
