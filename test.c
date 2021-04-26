#include "ft_printf.h"

int     main()
{
    ft_printf("meu |%*.*s|\n", 10, 7, "erick");
    printf("    |%*.*s|\n", 10, 7, "erick");
}
