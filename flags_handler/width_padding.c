#include "../ft_printf.h"

static void	padding_zeros(t_flag_count fc, char *str, int *inc)
{
	while (fc.width)
	{
		*(str + *inc) = '0';
		fc.width--;
		(*inc)++;
	}
}

static void	padding_spaces(t_flag_count fc, char *str, int *inc)
{
	while (fc.width)
	{
		*(str + *inc) = ' ';
		fc.width--;
		(*inc)++;
	}
}

static void	padding_one_space(char *str, int *inc)
{
	*(str + (*inc)) = ' ';
	(*inc)++;
}

char	*width_padding(t_flag_count fc)
{
	char	*str;
	int		inc;

	inc = 0;
	str = malloc(fc.width);
	if (fc.width > 0 && fc.zero > 0 && !(fc.less > 0) && (!(fc.precision > 0)))
		padding_zeros(fc, str, &inc);
	else if (fc.width > 0)
		padding_spaces(fc, str, &inc);
	else if (fc.zero > 0 || fc.less > 0)
		padding_one_space(str, &inc);
	*(str + inc) = '\0';
	return (str);
}
