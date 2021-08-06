#include "../ft_printf.h"

char	*format_finder(char c, va_list ap, t_flag_count s_fc)
{
	if (c == 'd' || c == 'i')
		return (format_d(va_arg(ap, int), s_fc));
	else if (c == 'c')
		return (format_c(va_arg(ap, int), s_fc));
	else if (c == 's')
		return (format_s(va_arg(ap, char *), s_fc));
	else if (c == 'p')
		return (format_p(va_arg(ap, unsigned long), s_fc));
	else if (c == 'u')
		return (format_u(va_arg(ap, unsigned int), s_fc));
	else if (c == 'x')
		return (format_x(va_arg(ap, unsigned long), s_fc));
	else if (c == 'X')
		return (format_X(va_arg(ap, unsigned long), s_fc));
	else if (c == '%')
		return (format_percent());
	else
		return (NULL);
}
