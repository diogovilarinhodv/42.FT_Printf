#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flag_count
{
	int	space;
	int	plus;
	int	less;
	int	zero;
	int	cardinal;
	int	dot;
	int	width;
	int	percent_finded;
}	t_flag_count;

int		ft_printf(const char *str, ...);
char	*ft_unsigned_itoa(unsigned int n);

// LIBFT
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_atoi(const char *nptr);

// CONVERTS
char	*dec_to_hexa_p(unsigned long num);
char	*dec_to_hexa_x(unsigned long num);
char	*dec_to_hexa_X(unsigned long num);

// FORMATS
char	*format_c(int chr);
char	*format_d(int num, t_flag_count s_fc);
char	*format_p(unsigned long num);
char	*format_percent(void);
char	*format_s(char *s);
char	*format_u(unsigned int num, t_flag_count fc);
char	*format_x(unsigned long num, t_flag_count s_fc);
char	*format_X(unsigned long num, t_flag_count s_fc);

// UTILS
int		check_format(char c);
void	count_flag(const char *str, int *inc, t_flag_count *fc);
int		reset_count_flag(t_flag_count *s_fc);
char	*format_finder(char c, va_list ap, t_flag_count s_fc);

#endif