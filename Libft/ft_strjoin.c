#include "libft.h"

static void	str_write(char *p, char const *s, int *cnt, int *inc)
{
	*(p + *inc) = *(s + *cnt);
	*cnt += 1;
	*inc += 1;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		cnt;
	int		inc;
	char	*p;

	cnt = 0;
	inc = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	p = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (p == NULL)
		return (NULL);
	while (*(s1 + cnt) != '\0')
		str_write(p, s1, &cnt, &inc);
	cnt = 0;
	while (*(s2 + cnt) != '\0')
		str_write(p, s2, &cnt, &inc);
	*(p + inc) = '\0';
	return (p);
}
