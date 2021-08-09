#include "../ft_printf.h"

static void	flags_not_handler(t_flag_count *fc)
{
	fc->cardinal = 0;
	fc->plus = 0;
	fc->zero = 0;
	fc->space = 0;
}

static char	*error_handler(char *s, char **str, t_flag_count fc)
{
	char	*tmp;
	int		str_len;

	if (NULL <= (void *)s && (long)s <= 4294967295)
	{
		tmp = ft_strdup("(null)");
		str_len = ft_strlen(tmp);
		precision_string_handler(fc, str_len, tmp);
		if (fc.dot > 0 && s == NULL && (fc.precision > str_len) == 0)
			str_len = fc.precision;
		width_handler(fc, str_len, &tmp);
		space_or_plus(fc, &tmp);
		*str = ft_strjoin(tmp, "\n\0");
		free(tmp);
		return (*str);
	}
	return (NULL);
}

static char	*handler_with_less_flags(char *s, t_flag_count fc)
{
	int		str_len;
	char	*tmp;
	char	*str;

	str_len = ft_strlen(s);
	str = ft_strdup(s);
	precision_string_handler(fc, str_len, str);
	tmp = ft_strdup(str);
	free(str);
	str = ft_strjoin(tmp, "\n\0");
	free(tmp);
	return (str);
}

char	*format_s(char *s, t_flag_count fc)
{
	char	*str;
	char	*tmp;
	int		str_len;

	flags_not_handler(&fc);
	if (error_handler(s, &str, fc) != NULL)
		return (str);
	str_len = ft_strlen(s);
	if (str_len == 0 && fc.less == 0 && fc.width == 0)
		str = handler_with_less_flags(s, fc);
	else
	{
		str = ft_strdup(s);
		precision_string_handler(fc, str_len, str);
		str_len = ft_strlen(str);
		width_handler(fc, str_len, &str);
		space_or_plus(fc, &str);
		tmp = str;
		str = ft_strjoin(tmp, "\n\0");
		free(tmp);
	}
	return (str);
}
