#include "ft_printf.h"

int     main()
{
    ft_printf("|%-*.30x|\n", 40, 42);
    printf("|%-*.30x|\n", 40, 42);
}
