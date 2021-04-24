#include "ft_printf.h"

int		main(void)
{
	ft_printf("meu : |%*.*u|\n", 25, 30, 42);
	printf("    : |%*.*u|\n", 25, 30, 42);
	ft_printf("meu : |%-*.*x|\n", -10, 5, -42);
	printf("    : |%-*.*x|\n", -10, -5, -42);
	ft_printf("meu : |%*.*i|\n", 10, -20, 42);
	printf("    : |%*.*i|\n", 10, -20, 42);
}
