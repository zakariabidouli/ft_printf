#include <stdarg.h>
#include <unistd.h>

int print(const char *form, int count)
{

}

int	ft_printf(const char *form, ...)
{
	va_list	args;
	int output;

	output = 0; 
	va_start(args, form);

	
	 	output = va_arg(args, form);
	va_end(args);
	return (0);
} 	
