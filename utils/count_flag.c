#include "../ft_printf.h"

void	count_flag(const char *str, int *inc, t_flag_count *fc)
{
	char	ch;

	ch = *(str + (*inc));
	if (ch == '#')
		fc->cardinal++;
	else if (ch == ' ')
		fc->space++;
	else if (ch == '+')
		fc->plus++;
	else if (ch == '0')
		fc->zero++;
	else if (ch == '-')
		fc->less++;
	else if (ch == '.')
		fc->dot++;
	else if ('1' <= ch && ch <= '9' && fc->dot == 0)
		fc->width = calc_width(str, inc);
	else if (('1' <= ch && ch <= '9') && fc->dot > 0)
		fc->precision = calc_width(str, inc);
	(*inc)++;
}
