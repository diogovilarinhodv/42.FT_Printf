#include "../ft_printf.h"

static void	less_with_width_pad(t_flag_count fc, char **r, char *str_pad)
{
	char	*tmp;

	if (**r == '-' && !(fc.less > 0))
	{
		**r = *str_pad;
		*str_pad = '-';
	}
	if (fc.less > 0)
		tmp = ft_strjoin(*r, str_pad);
	else
		tmp = ft_strjoin(str_pad, *r);
	free(str_pad);
	free(*r);
	*r = ft_strdup(tmp);
	free(tmp);
}

static void	width_padding(t_flag_count fc, int str_len, char **r)
{
	char	*str_pad;

	if ((fc.plus || fc.space) && **r != '-')
		fc.width--;
	if (fc.width > str_len && fc.width > 0)
	{
		str_pad = str_padding(str_len, fc);
		less_with_width_pad(fc, r, str_pad);
	}
}

static void	zero_case(int *zero_finder, char **tmp)
{
	if (*zero_finder)
	{
		*zero_finder = 0;
		while (*((*tmp) + *zero_finder) == 'a')
			(*zero_finder)++;
		*((*tmp) + *zero_finder - 1) = '\0';
	}
}

char	*format_c(int chr, t_flag_count fc)
{
	char	*c;
	char	*tmp;
	int		str_len;
	int		zero_finder;

	zero_finder = 0;
	c = malloc(2);
	*c = (char)chr;
	*(c + 1) = '\0';
	if (*c == '\0')
	{
		*c = 'a';
		zero_finder = 1;
	}
	str_len = 1;
	width_padding(fc, str_len, &c);
	tmp = ft_strjoin(c, "\n\0");
	free(c);
	zero_case(&zero_finder, &tmp);
	c = tmp;
	return (c);
}
