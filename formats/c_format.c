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

static int	zero_case_start(char **c)
{
	if (**c == '\0')
	{
		**c = 'a';
		return (1);
	}
	return (0);
}

static void	zero_case_end(int *zero_finder, char **tmp)
{
	if (*zero_finder)
	{
		*zero_finder = 0;
		while (*((*tmp) + *zero_finder) == 'a')
			(*zero_finder)++;
		*((*tmp) + *zero_finder - 1) = '\0';
	}
}

char	*format_c(int chr, t_flag_count fc)
{
	char	*c;
	char	*tmp;
	int		zero_finder;

	zero_finder = 0;
	c = malloc(2);
	*c = (char)chr;
	*(c + 1) = '\0';
	zero_finder = zero_case_start(&c);
	flags_not_handler(&fc);
	width_handler(fc, 1, &c);
	tmp = ft_strjoin(c, "\n\0");
	free(c);
	zero_case_end(&zero_finder, &tmp);
	c = tmp;
	return (c);
}
