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
	{write(1, "(null)", 6);
	return(6);}
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}