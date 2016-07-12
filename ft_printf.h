/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:13:39 by alegent           #+#    #+#             */
/*   Updated: 2016/07/12 11:22:51 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <locale.h>
# include <wchar.h>

/*
** TYPE DEFINES
*/

# define FLAG '%'
# define CHAR (1 << 0)
# define STR (1 << 1)
# define INT (1 << 2)
# define SIGNED (1 << 3)
# define DEC (1 << 4)
# define HEXA (1 << 5)
# define OCTAL (1 << 6)
# define MAJ (1 << 7)
# define POINTER (1 << 18)
# define BINARY (1 << 20)

/*
** MODIFIER DEFINES
*/

# define MOD_L (1 << 8)
# define MOD_LL (1 << 9)
# define MOD_H (1 << 10)
# define MOD_HH (1 << 11)
# define MOD_J (1 << 12)
# define MOD_Z (1 << 13)

/*
** OPT_DEFINE
*/

# define OPT_SHARP (1 << 14)
# define OPT_PLUS (1 << 15)
# define OPT_SPACE (1 << 16)
# define OPT_ZERO (1 << 17)
# define OPT_MINUS (1 << 19)

/*
** UNDEFINED FOR NOW
*/

# define WIDE (1 << 21)
# define T_FLAG (1 << 22)

/*
** STR DEFINE
*/

# define TYPE "dDisSpcCoOuxXb"
# define OPT "-+ #0"
# define MODIF "lhjz"
# define INTERGER "dDibuUoOxX"

/*
** TYPEDEF
*/

typedef struct s_pf		t_pf;
typedef struct s_nd		t_nd;

/*
** STRUCTURES
*/

struct					s_pf
{
	va_list				ap;
	int					fd;
	int					value;
	const char			*format;
};

struct					s_nd
{
	int					opt;
	int					precision;
	int					weight;
};

/*
** PRINTF PROTOTYPE
*/

int						ft_printf(const char *format, ...);
int						ft_dprintf(int fd, const char *format, ...);

/*
** CONVERSION
*/

char					*itoa_base(int nbr, int base);
char					*uitoa_base(unsigned int nbr, int base);
char					*itoa_base_long(long nbr, int base);
char					*uitoa_base_long(unsigned long nbr, int base);
char					*itoa_base_long_long(long long nbr, int base);
char					*uitoa_base_long_long(unsigned long long nbr, int base);

/*
** PARSING
*/

t_nd					parsing(t_pf *pf);
void					get_opt(t_pf *pf, t_nd *nd);
void					get_weight(t_pf *pf, t_nd *nd);
void					get_precision(t_pf *pf, t_nd *nd);
void					get_modifier(t_pf *pf, t_nd *nd);
void					get_type(t_pf *pf, t_nd *nd);

/*
** PRINT
*/

void					print_char(t_pf *pf, char c);
void					print_str(t_pf *pf, char *str);
void					print_n_char(t_pf *pf, char *str, int len);
void					print_weight(t_pf *pf, t_nd *nd, char **str);
void					print_minus_weight(t_pf *pf, int len);

/*
** READING
*/

void					read_node(t_pf *pf, t_nd nd);
void					read_str(t_pf *pf, t_nd *nd);
void					read_char(t_pf *pf, t_nd *nd);
void					read_int(t_pf *pf, t_nd *nd);
void					read_uint(t_pf *pf, t_nd *nd);
void					read_octal(t_pf *pf, t_nd *nd);
void					read_hexa(t_pf *pf, t_nd *nd);
void					read_ptr(t_pf *pf, t_nd *nd);
void					read_binary(t_pf *pf, t_nd *nd);
void					read_flag(t_pf *pf, t_nd *nd);

/*
** TOOLS
*/

t_bool					isin(char *str, char c);
t_bool					islower_case(char c);
char					*upcase_str(char *str);

#endif
