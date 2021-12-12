#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar_fd(char c);
void	ft_putnbr_fd(int nb);
void	ft_putstr_fd(char *s);
int		ft_strlen(const	char	*str);
int		ft_put_hex(unsigned int num, const char format);
int		ft_putpercent(void);

#endif