#include <printf.h>

int	ft_strlen(const	char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	if (!(s))
		return ;
	write(1, s, ft_strlen(s));
}