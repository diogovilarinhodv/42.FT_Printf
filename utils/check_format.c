#include "../ft_printf.h"

int	check_format(char c)
{
	if (c == 'd' || c == 'i' || c == 'c' || c == 's')
		return (1);
	else if (c == 'p' || c == 'x' || c == 'X' || c == 'u' || c == '%')
		return (1);
	return (0);
}
