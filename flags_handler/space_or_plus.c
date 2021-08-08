#include "../ft_printf.h"

void	space_or_plus(t_flag_count fc, char **r)
{
	char	*tmp;

	tmp = *r;
	if (fc.space > 0 && **r != '-' && fc.plus == 0)
		*r = ft_strjoin(" ", tmp);
	else if (fc.plus > 0 && **r != '-')
		*r = ft_strjoin("+", tmp);
	else
		*r = ft_strdup(tmp);
	free(tmp);
}
