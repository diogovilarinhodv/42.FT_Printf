#include "../ft_printf.h"

static void	flags_not_handler(t_flag_count *fc)
{
	fc->cardinal = 0;
	fc->dot = 0;
	fc->plus = 0;
	fc->precision = 0;
	fc->space = 0;
	fc->zero = 0;
}

char	*format_p(unsigned long num, t_flag_count fc)
{
	char	*hexa;
	char	*hexa_result;
	int		str_len;

	hexa = dec_to_hexa_p(num);
	str_len = ft_strlen(hexa);
	flags_not_handler(&fc);
	width_handler(fc, str_len, &hexa);
	hexa_result = ft_strjoin(hexa, "\n\0");
	free(hexa);
	return (hexa_result);
}
