#include "ft_printf.h"

int		main(void)
{
	ft_printf("meu : |%*.*u|\n", -25, -10, -42);
	printf("    : |%*.*u|\n", -25, -10, -42);
	//ft_printf("meu : |%*.*u|\n", 8, -10, 42);
	//printf("    : |%*.*u|\n", 8, -10, 42);
	//ft_printf("meu : |%-*.*x|\n", -10, (-5), -42);
	//printf("    : |%-*.*x|\n", -10, -5, -42);
	//ft_printf("meu : |%0*.*i|\n", 10, -5, 42);
	//printf("    : |%0*.*i|\n", 10, -5, 42);
}
