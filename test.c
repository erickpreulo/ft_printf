#include "ft_printf.h"

int     main()
{
    /*ft_printf("meu |%*s|\n", -10, "erick");
    printf("    |%*s|\n", -10, "erick");
    ft_printf("meu |%*.9s|\n", -10, "erick");
    printf("    |%*.9s|\n", -10, "erick");*/
    ft_printf("meu |%1.*s|\n", -3, "erick");
    printf("    |%1.*s|\n", -3, "erick");
}
