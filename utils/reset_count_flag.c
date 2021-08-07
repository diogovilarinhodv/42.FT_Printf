#include "../ft_printf.h"

int	reset_count_flag(t_flag_count *fc)
{
	fc->cardinal = 0;
	fc->dot = 0;
	fc->less = 0;
	fc->plus = 0;
	fc->space = 0;
	fc->zero = 0;
	fc->width = 0;
	fc->percent_finded = 0;
	fc->precision = 0;
	return (1);
}
