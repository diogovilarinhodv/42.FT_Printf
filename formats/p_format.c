#include "../ft_printf.h"

char	*format_p(unsigned long num)
{
	char			*hexa;
	char			*hexa_result;

	hexa = dec_to_hexa_p(num);
	hexa_result = ft_strjoin(hexa, "\n\0");
	free(hexa);
	return (hexa_result);
}
