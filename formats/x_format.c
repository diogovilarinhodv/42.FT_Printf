#include "../ft_printf.h"

static void	flags_not_handler(t_flag_count *fc)
{
	fc->plus = 0;
	fc->space = 0;
}

char	*format_x(unsigned long num, t_flag_count fc)
{
	char	*r;
	char	*tmp;
	int		str_len;

	r = dec_to_hexa_x(num);
	str_len = ft_strlen(r);
	if (fc.dot > 0 && fc.precision == 0)
		*r = '\0';
	if (fc.cardinal > 0 && *r != '0')
		tmp = ft_strjoin("0x", r);
	else
		tmp = ft_strdup(r);
	free(r);
	r = tmp;
	flags_not_handler(&fc);
	precision_handler(fc, str_len, &r);
	str_len = ft_strlen(r);
	width_handler(fc, str_len, &r);
	tmp = r;
	r = ft_strjoin(tmp, "\n\0");
	free(tmp);
	return (r);
}
