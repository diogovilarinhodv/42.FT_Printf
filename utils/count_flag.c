#include "../ft_printf.h"

static void	width_flag_handler(t_flag_count *fc, char *ch)
{
	fc->width *= 10;
	fc->width += ft_atoi(ch);
}

static void	precision_flag_handler(t_flag_count *fc, char *ch)
{
	fc->precision *= 10;
	fc->precision += ft_atoi(ch);
}

void	count_flag(char c, t_flag_count *fc)
{
	char	*ch;

	ch = malloc(2);
	*ch = c;
	*(ch + 1) = '\0';
	if (*ch == '#')
		fc->cardinal++;
	else if (*ch == ' ')
		fc->space++;
	else if (*ch == '+')
		fc->plus++;
	else if (*ch == '0' && !(fc->width > 0 || fc->precision))
		fc->zero++;
	else if (*ch == '-')
		fc->less++;
	else if (*ch == '.')
		fc->dot++;
	else if ('0' <= *ch && *ch <= '9' && fc->dot == 0)
		width_flag_handler(fc, ch);
	else if (('0' <= *ch && *ch <= '9') && fc->dot > 0)
		precision_flag_handler(fc, ch);
	free(ch);
}
