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
	if (fc.width > 0)
	{
		if (fc.space > 0 && **r != '-' && fc.plus == 0)
			*r = ft_strjoin(" ", tmp);
		else if (fc.plus > 0 && **r != '-')
			*r = ft_strjoin("+", tmp);
		else
			*r = ft_strdup(tmp);
		free(tmp);
	}
}

char	*format_s(char *s, t_flag_count fc)
{
	char	*str;
	char	*tmp;
	int		str_len;

	if (s == NULL)
		str = ft_strjoin("(null)", "\n\0");
	else if (ft_strlen(s) == 0 && fc.less == 0 && fc.width == 0)
	{
		str = ft_strdup(s);
		tmp = str;
		str = ft_strjoin(tmp, "\n\0");
		free(tmp);
	}
	else
	{
		str = ft_strdup(s);
		str_len = ft_strlen(str);
		width_padding(fc, str_len, &str);
		space_or_plus_padding(fc, &str);
		tmp = str;
		str = ft_strjoin(tmp, "\n\0");
		free(tmp);
	}
	return (str);
}
