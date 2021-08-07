#include "../ft_printf.h"

static void	padding_zeros(t_flag_count fc, int str_len, char *str, int *inc)
{
	while (fc.width - str_len)
	{
		*(str + *inc) = '0';
		fc.width--;
		(*inc)++;
	}
}

static void	padding_spaces(t_flag_count fc, int str_len, char *str, int *inc)
{
	while (fc.width - str_len)
	{
		*(str + *inc) = ' ';
		fc.width--;
		(*inc)++;
	}
}

char	*str_padding(int str_len, t_flag_count fc)
{
	char	*str;
	int		inc;

	inc = 0;
	str = malloc(fc.width - str_len);
	if (fc.width > 0 && fc.zero > 0 && !(fc.less > 0))
		padding_zeros(fc, str_len, str, &inc);
	else if (fc.width > 0)
		padding_spaces(fc, str_len, str, &inc);
	else if (fc.zero > 0 || fc.less > 0)
	{
		*(str + inc) = ' ';
		inc++;
	}
	*(str + inc) = '\0';
	return (str);
}
