#include "ft_printf.h"

int     main()
{
    ft_printf("|%*.0s|\n", 10, "erick");
    printf("|%*.0s|\n", 10, "erick");
}
