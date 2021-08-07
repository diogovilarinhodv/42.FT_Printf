#include "../ft_printf.h"

int	ff_writer(char *result)
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
