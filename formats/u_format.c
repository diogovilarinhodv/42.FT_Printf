#include "../ft_printf.h"

static void less_with_width_pad(t_flag_count fc, char **r, char *str_pad)
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

static void	space_or_plus_padding(t_flag_count fc, char **r)
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

char	*format_u(unsigned int num, t_flag_count fc)
{
	char	*r;
	char	*tmp;
	int		str_len;

	r = ft_unsigned_itoa(num);
	str_len = ft_strlen(r);
	width_padding(fc, str_len, &r);
	space_or_plus_padding(fc, &r);
	tmp = ft_strjoin(r, "\n\0");
	free(r);
	return (tmp);
}
