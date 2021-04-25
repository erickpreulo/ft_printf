#include "ft_printf.h"

int     main()
{
    ft_printf("|%*s|\n", 1, "123");
    printf("|%*s|\n", 1, "123");
    ft_printf("|%*.*s|\n", 15, -8, "erick");
    printf("|%*.*s|\n", 15, -8, "erick");
    ft_printf("|%*.*s|\n", 15, 8, "erick");
    printf("|%*.*s|\n", 15, 8, "erick");
}