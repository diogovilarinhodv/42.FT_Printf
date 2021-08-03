#include "../ft_printf.h"

static void	width_sup(int str_len, t_flag_count fc, char *str, int *inc)
{
	if (fc.width > 0 && fc.zero > 0 && !(fc.less > 0))
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
	else if (fc.zero > 0 || fc.less > 0)
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
		if (**r == '-' && !(fc.less > 0))
		{
			**r = *str_helper;
			*str_helper = '-';
		}
		if (fc.less > 0)
		{
			*((*r) + ft_strlen(*r) - 1) = '\0';
			tmp = ft_strjoin(*r, str_helper);
			free(*r);
			*r = ft_strjoin(tmp, "\n\0");
			free(tmp);
			tmp = ft_strdup(*r);
		}
		else
			tmp = ft_strjoin(str_helper, *r);
		free(str_helper);
		free(*r);
		*r = ft_strdup(tmp);
		free(tmp);
	}
}

static void	flags_calcs_2(t_flag_count fc, char **r)
{
	char	*tmp;

	tmp = *r;
	if (fc.space > 0 && **r != '-' && fc.plus == 0)
		*r = ft_strjoin(" ", tmp);
	else if (fc.plus > 0 && **r != '-')
		*r = ft_strjoin("+", tmp);
	else
		*r = ft_strdup(tmp);
	free(tmp);
}

char	*format_d(int num, t_flag_count fc)
{
	char	*r;
	char	*tmp;
	int		str_len;

	r = ft_itoa(num);
	str_len = ft_strlen(r);
	tmp = r;
	r = ft_strjoin(tmp, "\n\0");
	free(tmp);
	flags_calcs(fc, str_len, &r);
	flags_calcs_2(fc, &r);
	return (r);
}
