#include "../ft_printf.h"

void	precision_string_handler(t_flag_count fc, int str_len, char *str)
{
	str_len = ft_strlen(str) - fc.precision;
	if (fc.dot > 0)
	{
		if (str_len)
			*(str + fc.precision) = '\0';
		else
		{
			str_len = ft_strlen(str);
			*(str + str_len) = '\0';
		}
	}
}
