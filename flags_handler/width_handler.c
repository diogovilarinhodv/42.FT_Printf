#include "../ft_printf.h"

void	width_handler(t_flag_count fc, int str_len, char **r)
{
	char	*str_pad;

	if ((fc.plus || fc.space) && **r != '-')
		fc.width--;
	fc.width -= str_len;
	if (fc.width > 0)
	{
		str_pad = width_padding(fc);
		less_with_width(fc, r, str_pad);
	}
}
