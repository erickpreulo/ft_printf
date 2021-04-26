#include "ft_printf.h"

int     main()
{
    ft_printf("meu |%20.*s|\n", 3, "erick");
    printf("    |%20.*s|\n", 3, "erick");
}
