#include "ft_printf.h"

static int	writer(char *result)
{
	int	inc;

	inc = 0;
	while (!(*(result + inc) == '\n' && *(result + inc + 1) == '\0'))
	{
		write(1, (result + inc), 1);
		inc++;
	}
	return (inc);
}

static int	get_result(const char *str, va_list ap, int *inc, t_flag_count s_fc)
{
	int		lines_writed;
	char	*result;

	lines_writed = 0;
	result = format_finder(*(str + *inc), ap, s_fc);
	if (result != NULL)
		lines_writed = writer(result);
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

static void	inic(int *inc, t_flag_count *fc, int *count_result)
{
	*inc = 0;
	*count_result = 0;
	fc->percent_finded = 0;
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	int				inc;
	int				count_result;
	t_flag_count	s_fc;

	inic(&inc, &s_fc, &count_result);
	va_start(ap, str);
	while (*(str + inc) != '\0')
	{
		while (s_fc.percent_finded && *(str + inc) != '\0')
		{
			if (check_format(*(str + inc)))
			{
				count_result += get_result(str, ap, &inc, s_fc);
				break ;
			}
			count_flag(str, &inc, &s_fc);
		}
		if (reset_and_writer(str, &inc, &s_fc, &count_result) == -1)
			break ;
		inc++;
	}
	va_end(ap);
	return (count_result);
}
