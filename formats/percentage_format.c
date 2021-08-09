#include "../ft_printf.h"

char	*format_percent(t_flag_count fc)
{
	char	*str;
	char	*tmp;
	int		str_len;

	str = malloc(2);
	*(str) = '%';
	*(str + 1) = '\0';
	str_len = ft_strlen(str);
	precision_handler(fc, str_len, &str);
	str_len = ft_strlen(str);
	width_handler(fc, str_len, &str);
	tmp = str;
	str = ft_strjoin(tmp, "\n\0");
	free(tmp);
	return (str);
}
