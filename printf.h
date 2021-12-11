#ifndef PRINTF_H
# define PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *format, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putstr_fd(char *s, int fd);
int	ft_strlen(const	char	*str);

#endif