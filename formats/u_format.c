#include "../ft_printf.h"

static void	flags_not_handler(t_flag_count *fc)
{
	fc->cardinal = 0;
	fc->plus = 0;
	fc->space = 0;
}

char	*format_u(unsigned int num, t_flag_count fc)
{
	char	*r;
	char	*tmp;
	int		str_len;

	r = ft_unsigned_itoa(num);
	str_len = ft_strlen(r);
	flags_not_handler(&fc);
	precision_handler(fc, str_len, &r);
	str_len = ft_strlen(r);
	width_handler(fc, str_len, &r);
	space_or_plus(fc, &r);
	tmp = ft_strjoin(r, "\n\0");
	free(r);
	return (tmp);
}
