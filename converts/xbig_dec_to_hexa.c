#include "../ft_printf.h"

static int	wrong_input(unsigned long num, char **tmp, char **result)
{
	if (num < (unsigned long)1 || num == (unsigned long)(-__LONG_MAX__ - 1L))
	{
		*(*tmp) = '0';
		*(*tmp + 1) = '\0';
		free(*result);
		return (1);
	}
	return (0);
}

static void	to_hexa(unsigned long num, char **result, char **tmp)
{
	long	value;
	int		count;

	value = 0;
	count = 0;
	while (num)
	{
		value = num % 16;
		if (value < 10)
			*((*result) + count) = 48 + value;
		else
			*((*result) + count) = 55 + value;
		num /= 16;
		count++;
		if (count == 8)
			break ;
	}
	*((*result) + count) = '\0';
	*((*tmp) + count) = '\0';
}

static void	revert_string(char **result, char **tmp)
{
	int	count;

	count = 0;
	while (*((*result) + count) != '\0')
	{
		*((*tmp) + ft_strlen(*result) - count - 1) = *((*result) + count);
		count++;
	}
	free(*result);
	count = 0;
	while (*((*tmp) + count) == '0')
		count++;
	if (count == 8)
		*((*tmp) + 1) = '\0';
}

static void	remove_left_zeros(char **tmp)
{
	int		cnt;
	int		inc;

	cnt = 0;
	inc = 0;
	while (*((*tmp) + cnt) == '0')
		cnt++;
	while (*((*tmp) + cnt) != '\0')
	{
		*((*tmp) + inc) = *((*tmp) + cnt);
		inc++;
		cnt++;
	}
	*((*tmp) + inc) = '\0';
}

char	*dec_to_hexa_X(unsigned long num)
{
	char	*result;
	char	*tmp;

	result = malloc(9);
	tmp = malloc(9);
	if (result == NULL || tmp == NULL)
		return (NULL);
	if (wrong_input(num, &tmp, &result))
		return (tmp);
	to_hexa(num, &result, &tmp);
	revert_string(&result, &tmp);
	if (ft_strlen(tmp) > 1)
		remove_left_zeros(&tmp);
	return (tmp);
}
