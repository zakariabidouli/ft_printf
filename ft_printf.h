#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putstr(char *s);
int		ft_put_hex(unsigned int num, const char format);
int		ft_putpercent(void);
int		ft_put_ptr(unsigned long long ptr);

#endif