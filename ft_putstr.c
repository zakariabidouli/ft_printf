#include "ft_printf.h"

int	ft_strlen(const	char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr(char *s)
{
	if (!(s))
		return (0);
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}