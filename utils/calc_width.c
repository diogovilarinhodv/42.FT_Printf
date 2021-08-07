#include "../ft_printf.h"

int	calc_width(const char *str, int *inc)
{
	char	*str_num;
	int		inc_num;
	int		width;

	inc_num = 0;
	str_num = malloc(99);
	while ('0' <= *(str + (*inc)) && *(str + (*inc)) <= '9')
	{
		*(str_num + inc_num) += *(str + (*inc));
		inc_num++;
		(*inc)++;
	}
	(*inc)--;
	*(str_num + inc_num) = '\0';
	width = ft_atoi(str_num);
	free(str_num);
	return (width);
}
