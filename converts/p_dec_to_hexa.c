#include "../ft_printf.h"

static int	inicialization(char **tmp, char **result, unsigned long num)
{
	*((*tmp)) = '0';
	*((*tmp) + 1) = 'x';
	if (num < 1)
	{
		*((*tmp) + 2) = '0';
		*((*tmp) + 3) = '\0';
		free(*result);
		return (1);
	}
	return (0);
}

static void	revert_string(char **tmp, char **result)
{
	int	count;

	count = 0;
	while (*((*result) + count) != '\0')
	{
		*((*tmp) + ft_strlen(*result) - count + 1) = *((*result) + count);
		count++;
	}
	free(*result);
}

static void	to_hexa(char **tmp, char **result, unsigned long num)
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
			*((*result) + count) = 87 + value;
		num /= 16;
		count++;
	}
	*((*result) + count) = '\0';
	*((*tmp) + count + 2) = '\0';
}

char	*dec_to_hexa_p(unsigned long num)
{
	long	value;
	char	*result;
	char	*tmp;
	int		count;

	value = 0;
	count = 0;
	result = malloc(30);
	tmp = malloc(30);
	if (inicialization(&tmp, &result, num))
		return (tmp);
	to_hexa(&tmp, &result, num);
	revert_string(&tmp, &result);
	return (tmp);
}
