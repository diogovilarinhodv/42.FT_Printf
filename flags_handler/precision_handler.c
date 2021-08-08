#include "../ft_printf.h"

static void	less_signal_handler(char **r, char *str_pad)
{
	if (**r == '-')
	{
		**r = *str_pad;
		*str_pad = '-';
	}
}

void	precision_handler(t_flag_count fc, int str_len, char **r)
{
	char	*str_pad;
	char	*tmp;

	str_pad = NULL;
	tmp = NULL;
	if (**r == '-')
		fc.precision++;
	if (fc.precision > str_len && fc.precision > 0)
	{
		str_pad = precision_padding(str_len, fc);
		less_signal_handler(r, str_pad);
		tmp = *r;
		*r = ft_strjoin(str_pad, tmp);
		free(tmp);
		free(str_pad);
	}
}
