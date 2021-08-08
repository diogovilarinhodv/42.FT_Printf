#include "../ft_printf.h"

static void	flags_not_handler(t_flag_count *fc)
{
	fc->cardinal = 0;
	fc->plus = 0;
	fc->zero = 0;
	fc->space = 0;
}

static char	*error_handler(char *s, char **str)
{
	if (s == NULL)
	{
		*str = ft_strjoin("(null)", "\n\0");
		return (*str);
	}
	return (NULL);
}

char	*format_s(char *s, t_flag_count fc)
{
	char	*str;
	char	*tmp;
	int		str_len;

	flags_not_handler(&fc);
	if (error_handler(s, &str) != NULL)
		return (str);
	str_len = ft_strlen(s);
	if (str_len == 0 && fc.less == 0 && fc.width == 0)
	{
		tmp = ft_strdup(s);
		str = ft_strjoin(tmp, "\n\0");
		free(tmp);
	}
	else
	{
		str = ft_strdup(s);
		width_handler(fc, str_len, &str);
		space_or_plus(fc, &str);
		tmp = str;
		str = ft_strjoin(tmp, "\n\0");
		free(tmp);
	}
	precision_string_handler(fc, str_len, str);
	return (str);
}
