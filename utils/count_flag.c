#include "../ft_printf.h"

static int	calc_width(const char *str, int *inc)
{
	char	*num;
	int		i_num;
	int		result;

	i_num = 0;
	num = malloc(99);
	while ('0' <= *(str + (*inc)) && *(str + (*inc)) <= '9')
	{
		*(num + i_num) += *(str + (*inc));
		i_num++;
		(*inc)++;
	}
	(*inc)--;
	*(num + i_num) = '\0';
	result = ft_atoi(num);
	free(num);
	return (result);
}

void	count_flag(const char *str, int *inc, t_flag_count *fc)
{
	if (*(str + (*inc)) == '#')
		fc->cardinal++;
	if (*(str + (*inc)) == ' ')
		fc->space++;
	if (*(str + (*inc)) == '+')
		fc->plus++;
	if (*(str + (*inc)) == '0')
		fc->zero++;
	if (*(str + (*inc)) == '-')
		fc->less++;
	if (*(str + (*inc)) == '.')
		fc->dot++;
	if ('1' <= *(str + (*inc)) && *(str + (*inc)) <= '9')
		fc->width = calc_width(str, inc);
	(*inc)++;
}
