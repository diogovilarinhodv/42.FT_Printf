#include "../ft_printf.h"

static void	width_sup(int str_len, t_flag_count fc, char *str, int *inc)
{
	if (fc.width > 0 && fc.zero > 0)
	{
		while (fc.width - str_len)
		{
			*(str + *inc) = '0';
			fc.width--;
			(*inc)++;
		}
	}
	else if (fc.width > 0)
	{
		while (fc.width - str_len)
		{
			*(str + *inc) = ' ';
			fc.width--;
			(*inc)++;
		}
	}
	else if (fc.zero > 0)
	{
		*(str + *inc) = ' ';
		(*inc)++;
	}
}

static char	*width_calcs(int str_len, t_flag_count fc)
{
	char	*str;
	int		inc;

	inc = 0;
	str = malloc(fc.width - str_len);
	width_sup(str_len, fc, str, &inc);
	*(str + inc) = '\0';
	return (str);
}

static void	flags_calcs(t_flag_count fc, int str_len, char **r)
{
	char	*str_helper;
	char	*tmp;

	if ((fc.plus || fc.space) && **r != '-')
		str_len++;
	if (fc.width > str_len && fc.width > 0)
	{
		str_helper = width_calcs(str_len, fc);
		if (**r == '-')
		{
			**r = *str_helper;
			*str_helper = '-';
		}
		tmp = ft_strjoin(str_helper, *r);
		free(str_helper);
		free(*r);
		*r = ft_strdup(tmp);
		free(tmp);
	}
}

char	*format_x(unsigned long num, t_flag_count fc)
{
	char	*r;
	char	*tmp;
	int		str_len;

	r = dec_to_hexa_x(num);
	str_len = ft_strlen(r);
	tmp = ft_strjoin(r, "\n\0");
	free(r);
	if (fc.cardinal > 0 && *tmp != '0')
		r = ft_strjoin("0x", tmp);
	else
		r = ft_strdup(tmp);
	free(tmp);
	flags_calcs(fc, str_len, &r);
	return (r);
}
