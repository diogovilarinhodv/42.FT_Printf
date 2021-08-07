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

char	*format_p(unsigned long num, t_flag_count fc)
{
	char	*hexa;
	char	*hexa_result;
	int		str_len;

	hexa = dec_to_hexa_p(num);
	str_len = ft_strlen(hexa);
	width_padding(fc, str_len, &hexa);
	hexa_result = ft_strjoin(hexa, "\n\0");
	free(hexa);
	return (hexa_result);
}
