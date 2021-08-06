#include "ft_printf.h"

static int	get_result(const char *str, va_list ap, int *inc, t_flag_count s_fc)
{
	int		lines_writed;
	char	*result;

	lines_writed = 0;
	result = format_finder(*(str + *inc), ap, s_fc);
	if (result != NULL)
		lines_writed = ff_writer(result);
	free(result);
	(*inc)++;
	return (lines_writed);
}

static int	reset_and_writer(const char *s, int *i, t_flag_count *fc, int *cr)
{
	if (*(s + (*i)) == '\0')
		return (-1);
	if (*(s + (*i)) == '%')
		fc->percent_finded = reset_count_flag(fc);
	else
	{
		fc->percent_finded = 0;
		write(1, (s + (*i)), 1);
		(*cr)++;
		return (1);
	}
	return (0);
}

static int	read_cycle(const char *str, va_list ap)
{
	t_flag_count	s_fc;
	int				inc;
	int				cnt_chars;

	inc = 0;
	cnt_chars = 0;
	s_fc.percent_finded = 0;
	while (*(str + inc) != '\0')
	{
		while (s_fc.percent_finded && *(str + inc) != '\0')
		{
			if (check_format(*(str + inc)))
			{
				cnt_chars += get_result(str, ap, &inc, s_fc);
				break ;
			}
			count_flag(str, &inc, &s_fc);
		}
		if (reset_and_writer(str, &inc, &s_fc, &cnt_chars) == -1)
			break ;
		inc++;
	}
	return (cnt_chars);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	int				writed_chars;

	writed_chars = 0;
	va_start(ap, str);
	writed_chars = read_cycle(str, ap);
	va_end(ap);
	return (writed_chars);
}
