/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artainmo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 20:18:02 by artainmo          #+#    #+#             */
/*   Updated: 2019/11/30 20:29:07 by artainmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>

typedef struct	s_flags
{
	int		blank_space;
	int		min_witdh;
	int		minus_flag;
	int		flag_0;
	int		precision;
	int		longs;
	int		long_long;
	int		shorts;
	int		chars;
	int		flag_point;
	double	negative;
	int		neg;
}				t_flags;

typedef struct	s_norm
{
	int		precision;
	char	*s;
}				t_norm;

extern int g_error;

int				ft_printf(const char *format, ...);
char			ft_find_modulo(const char *f, int *m, t_flags *fl, va_list *a);
void			ft_write_argument(char m, va_list *arg, int *r, t_flags *f);
void			ft_m_putstr(char *str, int *r, int p);
void			ft_m_h_putstr(char *str, int *r);
void			ft_m_putnbr(int nb, int *r);
void			ft_m_unsigned_putnbr(unsigned int nb, int *ret_str_l);
char			*ft_dec_to_hex_lowercase(unsigned long long int s);
char			*ft_decimal_to_hexadecimal_uppercase(unsigned long long int s);
char			*ft_ftoa(double n, int precision);
char			*ft_e_ftoa(double f, int precision);
char			*ft_g_ftoa(double f, int precision);
char			*ft_scientific_notatian(char *s, int precision);
char			*ft_g_no_insignificant(char *s);
char			*ft_g_e_no_insignificant(char *s);
char			*ft_ltoa(long long int n);
char			*ft_ultoa(unsigned long long int n);
int				ft_w_strlen(const wchar_t *str);
void			ft_m_w_putstr(wchar_t *str, int *ret_str_l, int precision);
void			ft_modulo_c(va_list *arguments, int *ret_str_l, t_flags *flags);
void			ft_min_witdh(int min_witdh, int *witdh, int *ret, t_flags *f);
void			ft_min_witdh_s(int min_witdh, int *witdh, int *ret, t_flags *f);
void			ft_int_precision(int *witdh, int *r, t_norm norm, int *i);
void			ft_ch_precision(int *witdh, int *r, t_norm norm, char *i);
void			ft_sh_precision(int *w, int *r, t_norm norm, short int *i);
void			ft_l_precision(int *witdh, int *r, t_norm norm, long int *i);
void			ft_ll_prec(int *w, int *r, t_norm norm, long long int *i);
void			ft_u_precision(int *w, int *r, t_norm norm, int m);
char			*ft_no_point_e(char *s, int *point);
char			*ft_no_point_f(char *s, int *point);
char			*ft_no_point_s(char *s, int *zero_counter);
char			*ft_no_point_g(char *s, int *point);
char			*ft_last_dece(char *str);
char			*ft_last_decf(char *str);
char			*ft_last_decg(char *str);
int				ft_count_b_zeros(char *str);
char			*ft_substr2(char *s, unsigned int start, unsigned int len);
char			*ft_last_dec2s(char *str, int *i);
char			*ft_set_point_p(char *s, int *zero_counter, int precision);
char			*ft_set_point_n(char *s, int z_c, int n_z_c, int p);
int				ft_e_non_zero_counter(char *s);
int				ft_e_zero_counter(char *s);
void			ft_bx1_writ(char m, t_flags *f, int *r, va_list *a);
void			ft_bx2_writ(char m, t_flags *f, int *r, va_list *a);
void			ft_i2_writ(char **s, t_flags *f, int *ret, va_list *a);
void			ft_i_writ(char **s, t_flags *f, int *ret, va_list *a);
void			ft_u2_writ(t_flags *flags, int *ret_str_l, va_list *a, char m);
void			ft_u_writ(t_flags *flags, int *ret_str_l, va_list *a, char m);
void			ft_x2_writ(char m, t_flags *flags, int *ret, va_list *a);
void			ft_x_writ(char m, t_flags *flags, int *ret, va_list *a);
char			ft_find_specifier2(char c, char cminone);
void			ft_modulo_hash(char m, va_list *a, int *r, t_flags *flags);
void			ft_modulo_plus(va_list *a, int *r, t_flags *flags);
void			ft_modulo_bx(char m, va_list *a, int *r, t_flags *flags);
void			ft_modulo_c(va_list *arguments, int *ret_str_l, t_flags *flags);
void			ft_modulo_e(va_list *arguments, int *ret_str_l, t_flags *flags);
void			ft_modulo_f(va_list *arguments, int *ret_str_l, t_flags *flags);
void			ft_modulo_g(va_list *arguments, int *ret_str_l, t_flags *flags);
void			ft_modulo_h(char m, va_list *a, int *ret_str_l, t_flags *flags);
void			ft_modulo_i(va_list *arguments, int *ret_str_l, t_flags *flags);
void			ft_modulo_n(va_list *arguments, int *ret_str_l, t_flags *flags);
void			ft_modulo_p(char m, va_list *a, int *ret_str_l, t_flags *flags);
void			ft_modulo_s(va_list *arguments, int *ret_str_l, t_flags *flags);
void			ft_modulo_u(char m, va_list *a, int *ret_str_l, t_flags *flags);
void			ft_modulo_x(char m, va_list *a, int *ret_str_l, t_flags *flags);
void			*ft_calloc(unsigned int count, unsigned int size);
int				ft_atoi(const char *str);
int				ft_strlen2(const char *str);
char			*ft_itoa2(int n);
char			*ft_utoa(unsigned int n);
char			*ft_strdup(const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
void			flag_comb(t_flags *flag, char m_t);
void			ft_flag_init(t_flags *flag);
char			*ft_zero_zero(char *str, int precision);

#endif
