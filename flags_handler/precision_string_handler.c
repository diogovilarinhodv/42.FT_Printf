#include "../ft_printf.h"

void	precision_string_handler(t_flag_count fc, int str_len, char *str)
{
	str_len = ft_strlen(str);
	if (fc.dot > 0)
	{
		if ((str_len - 1) < fc.precision)
		{
			*(str + (str_len - 1)) = '\n';
			*(str + (str_len - 1) + 1) = '\0';
		}
		else if (str_len)
		{
			*(str + fc.precision) = '\n';
			*(str + fc.precision + 1) = '\0';
		}
	}
}
