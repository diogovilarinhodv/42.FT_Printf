#include "../ft_printf.h"

char	*format_c(int chr)
{
	char	*c;

	c = malloc(3);
	*c = (char)chr;
	*(c + 1) = '\n';
	*(c + 2) = '\0';
	return (c);
}
