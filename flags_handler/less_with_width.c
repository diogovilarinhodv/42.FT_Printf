#include "../ft_printf.h"

static void	less_signal_handler(t_flag_count fc, char **r, char *str_pad)
{
	if (**r == '-' && !(fc.less > 0) && fc.zero > 0 && !(fc.dot > 0))
	{
		**r = *str_pad;
		*str_pad = '-';
	}
}

static void	less_flag_handler(t_flag_count fc, char **r, char *str_pad)
{
	char	*tmp;

	if (fc.less > 0)
		tmp = ft_strjoin(*r, str_pad);
	else
		tmp = ft_strjoin(str_pad, *r);
	free(str_pad);
	free(*r);
	*r = ft_strdup(tmp);
	free(tmp);
}

void	less_with_width(t_flag_count fc, char **r, char *str_pad)
{
	less_signal_handler(fc, r, str_pad);
	less_flag_handler(fc, r, str_pad);
}
