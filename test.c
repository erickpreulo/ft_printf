#include "ft_printf.h"

int     main()
{
    ft_printf("meu |%-100.*s|\n", 1, "erick");
    printf("    |%-100.*s|\n", 1, "erick");
}
