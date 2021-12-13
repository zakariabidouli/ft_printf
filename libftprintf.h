#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdarg.h>
#include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *s);
int		ft_strlen(const	char	*str);
int		ft_put_hex(unsigned int num, const char format);
int		ft_putpercent(void);
int		ft_put_ptr(unsigned long long ptr);

#endif