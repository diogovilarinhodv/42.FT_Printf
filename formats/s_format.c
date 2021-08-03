#include "../ft_printf.h"

char	*format_s(char *s)
{
	char	*str;

	if (s == NULL)
		str = ft_strjoin("(null)", "\n\0");
	else
		str = ft_strjoin(s, "\n\0");
	return (str);
}
