#include "../ft_printf.h"

void	count_flag(const char *str, int *inc, t_flag_count *fc)
{
	if (*(str + (*inc)) == '#')
		fc->cardinal++;
	if (*(str + (*inc)) == ' ')
		fc->space++;
	if (*(str + (*inc)) == '+')
		fc->plus++;
	if (*(str + (*inc)) == '0')
		fc->zero++;
	if (*(str + (*inc)) == '-')
		fc->less++;
	if (*(str + (*inc)) == '.')
		fc->dot++;
	if ('1' <= *(str + (*inc)) && *(str + (*inc)) <= '9')
		fc->width = calc_width(str, inc);
	(*inc)++;
}
