#include "../ft_printf.h"

char	*format_percent(void)
{
	char	*str;

	str = malloc(3);
	*(str) = '%';
	*(str + 1) = '\n';
	*(str + 2) = '\0';
	return (str);
}
