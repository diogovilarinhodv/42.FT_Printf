#include "../ft_printf.h"

static void	padding_zeros(t_flag_count fc, int str_len, char *str, int *inc)
{
	while (fc.precision - str_len)
	{
		*(str + *inc) = '0';
		fc.precision--;
		(*inc)++;
	}
}

char	*precision_padding(int str_len, t_flag_count fc)
{
	char	*str;
	int		inc;

	inc = 0;
	str = malloc(fc.precision - str_len);
	if (fc.precision > 0)
		padding_zeros(fc, str_len, str, &inc);
	*(str + inc) = '\0';
	return (str);
}
