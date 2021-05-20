#include "ft_printf.h"

int main()
{
	int x;
	int y;

	x = ft_printf("%--150.*d%01.172i%--151.122d%--*.110x%--23.182%" ,193,-1523409169,453642614,881460015,68,2920216226u);
	printf("|%d|\n", x);
	y = printf("%--150.*d%01.172i%--151.122d%--*.110x%--23.182%" ,193,-1523409169,453642614,881460015,68,2920216226u);
	printf("|%d|\n", y);
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
/*
	ft_printf("1:");ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j); //T2
	printf("1:");printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j); //T2
	ft_printf("2:");ft_printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", i, j, k, l, m, c, e, d); //T3
	printf("2:");printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", i, j, k, l, m, c, e, d); //T3
	ft_printf("3:");ft_printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d\n", i, j, k, l, m, c, e, d); //T4
	printf("3:");printf("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d\n", i, j, k, l, m, c, e, d); //T4
	ft_printf("4:");ft_printf("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d\n", i, j, k, l, m, c, e, d); //T5
	printf("4:");printf("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d\n", i, j, k, l, m, c, e, d); //T5
	ft_printf("5:");ft_printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d\n", i, j, k, l, m, c, e, d); //T6
	printf("5:");printf("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d\n", i, j, k, l, m, c, e, d); //T6
	ft_printf("6:");ft_printf("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d\n", i, j, k, l, m, c, e, d); //T7
	printf("6:");printf("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d\n", i, j, k, l, m, c, e, d); //T7
	ft_printf("7:");ft_printf("%5i, %5d, %5d, %5d, %5d, %5d, %5d, %5d\n", i, j, k, l, m, c, e, d); //T8
	printf("7:");printf("%5i, %5d, %5d, %5d, %5d, %5d, %5d, %5d\n", i, j, k, l, m, c, e, d); //T8
	ft_printf("8:");ft_printf("%6i, %6d, %6d, %6d, %6d, %6d, %6d, %6d\n", i, j, k, l, m, c, e, d); //T9
	printf("8:");printf("%6i, %6d, %6d, %6d, %6d, %6d, %6d, %6d\n", i, j, k, l, m, c, e, d); //T9
	ft_printf("9:");ft_printf("%7i, %7d, %7d, %7d, %7d, %7d, %7d, %7d\n", i, j, k, l, m, c, e, d); //T10
	printf("9:");printf("%7i, %7d, %7d, %7d, %7d, %7d, %7d, %7d\n", i, j, k, l, m, c, e, d); //T10
	ft_printf("10:");ft_printf("%8i, %8d, %8d, %8d, %8d, %8d, %8d, %8d\n", i, j, k, l, m, c, e, d); //T11
	printf("10:");printf("%8i, %8d, %8d, %8d, %8d, %8d, %8d, %8d\n", i, j, k, l, m, c, e, d); //T11
	ft_printf("11:");ft_printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d\n", i, j, k, l, m, c, e, d); //T12
	printf("11:");printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d\n", i, j, k, l, m, c, e, d); //T12
	ft_printf("12:");ft_printf("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d\n", i, j, k, l, m, c, e, d); //T13
	printf("12:");printf("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d\n", i, j, k, l, m, c, e, d); //T13
	ft_printf("13:");ft_printf("%0.0i, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d\n", i, j, k, l, m, c, e, d); //T14
	printf("13:");printf("%0.0i, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d\n", i, j, k, l, m, c, e, d); //T14
	ft_printf("14:");ft_printf("%-0i, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d\n", i, j, k, l, m, c, e, d); //T15
	printf("14:");printf("%-0i, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d\n", i, j, k, l, m, c, e, d); //T15
	ft_printf("15:");ft_printf("%0-i, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d\n", i, j, k, l, m, c, e, d); //T16
	printf("15:");printf("%0-i, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d\n", i, j, k, l, m, c, e, d); //T16
	ft_printf("16:");ft_printf("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d\n", i, j, k, l, m, c, e, d); //T17
	printf("16:");printf("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d\n", i, j, k, l, m, c, e, d); //T17
	ft_printf("17:");ft_printf("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d\n", i, j, k, l, m, c, e, d); //T18
	printf("17:");printf("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d\n", i, j, k, l, m, c, e, d); //T18
	ft_printf("18:");ft_printf("%-i, %-d, %-d, %-d, %-d, %-d, %-d, %-d\n", i, j, k, l, m, c, e, d); //T19
	printf("18:");printf("%-i, %-d, %-d, %-d, %-d, %-d, %-d, %-d\n", i, j, k, l, m, c, e, d); //T19
	ft_printf("19:");ft_printf("%.i, %.d, %.d, %.d, %.d, %.d, %.d, %.d\n", i, j, k, l, m, c, e, d); //T20
	printf("19:");printf("%.i, %.d, %.d, %.d, %.d, %.d, %.d, %.d\n", i, j, k, l, m, c, e, d); //T20
	ft_printf("20:");ft_printf("%-0.0i, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d\n", i, j, k, l, m, c, e, d); //T21
	printf("20:");printf("%-0.0i, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d\n", i, j, k, l, m, c, e, d); //T21
	ft_printf("21:");ft_printf("%00i, %00d, %00d, %00d, %00d, %00d, %00d, %00d\n", i, j, k, l, m, c, e, d); //T22
	printf("21:");printf("%00i, %00d, %00d, %00d, %00d, %00d, %00d, %00d\n", i, j, k, l, m, c, e, d); //T22
	ft_printf("22:");ft_printf("|%1.i|, |%1.d|, |%1.d|, |%1.d|, |%1.d|, |%1.d|, |%1.d|, |%1.d|\n", i, j, k, l, m, c, e, 2147483647); //T23
	printf("22:");printf("|%1.i|, |%1.d|, |%1.d|, |%1.d|, |%1.d|, |%1.d|, |%1.d|, |%1.d|\n", i, j, k, l, m, c, e, 2147483647); //T23
	ft_printf("23:");ft_printf("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d\n", i, j, k, l, m, c, e, d); //T24
	printf("23:");printf("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d\n", i, j, k, l, m, c, e, d); //T24
	ft_printf("24:");ft_printf("%1.1i, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d\n", i, j, k, l, m, c, e, d); //T25
	printf("24:");printf("%1.1i, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d\n", i, j, k, l, m, c, e, d); //T25
	ft_printf("25:");ft_printf("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d\n", i, j, k, l, m, c, e, d); //T26
	printf("25:");printf("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d\n", i, j, k, l, m, c, e, d); //T26
	ft_printf("26:");ft_printf("%-01i, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d\n", i, j, k, l, m, c, e, d); //T27
	printf("26:");printf("%-01i, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d\n", i, j, k, l, m, c, e, d); //T27
	ft_printf("27:");ft_printf("%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d, %-1d, %-1d\n", i, j, k, l, m, c, e, d); //T28
	printf("27:");printf("%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d, %-1d, %-1d\n", i, j, k, l, m, c, e, d); //T28
	ft_printf("28:");ft_printf("%-.1i, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d\n", i, j, k, l, m, c, e, d); //T29
	printf("28:");printf("%-.1i, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d\n", i, j, k, l, m, c, e, d); //T29
	ft_printf("29:");ft_printf("%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d\n", i, j, k, l, m, c, e, d); //T30
	printf("29:");printf("%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d\n", i, j, k, l, m, c, e, d); //T30
	ft_printf("30:");ft_printf("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d\n", i, j, k, l, m, c, e, d); //T31
	printf("30:");printf("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d\n", i, j, k, l, m, c, e, d); //T31
	ft_printf("31:");ft_printf("%-1.1i, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d\n", i, j, k, l, m, c, e, d); //T32
	printf("31:");printf("%-1.1i, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d\n", i, j, k, l, m, c, e, d); //T32
	ft_printf("32:");ft_printf("%1.0i, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d\n", i, j, k, l, m, c, e, d); //T33
	printf("32:");printf("%1.0i, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d\n", i, j, k, l, m, c, e, d); //T33
	while (a < 5) //T34-69
	{
		ft_printf("33: a: |%d| ", a);ft_printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		printf("33: a: |%d| ", a);printf("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		ft_printf("34: a: |%d| ", a);ft_printf("|%0*i|, %0*d, %0*d, |%0*d|, %0*d, %0*d, %0*d, %0*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		printf("34: a: |%d| ", a);printf("|%0*i|, %0*d, %0*d, |%0*d|, %0*d, %0*d, %0*d, %0*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		ft_printf("35: a: |%d| ", a);ft_printf("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		printf("35: a: |%d| ", a);printf("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		ft_printf("36: a: |%d| ", a);ft_printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		printf("36: a: |%d| ", a);printf("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d\n", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		a++;
	}
	a = -2;
	while(a < 5) //T70-177
	{
		b = -2;
		while (b < 5)
		{
			ft_printf("37: a: |%d| b: |%d|   ", a, b);ft_printf("|%*.*i|, |%*.*d|, |%*.*d|, |%*.*d|, |%*.*d|, |%*.*d|, |%*.*d|, |%*.*d|\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			printf("37: a: |%d| b: |%d|   ", a, b);printf("|%*.*i|, |%*.*d|, |%*.*d|, |%*.*d|, |%*.*d|, |%*.*d|, |%*.*d|, |%*.*d|\n\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			ft_printf("38: a: |%d| b: |%d|   ", a, b);ft_printf("|%-*.*i|, |%-*.*d|, |%-*.*d|, |%-*.*d|, |%-*.*d|, |%-*.*d|, |%-*.*d|, |%-*.*d|\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			printf("38: a: |%d| b: |%d|   ", a, b);printf("|%-*.*i|, |%-*.*d|, |%-*.*d|, |%-*.*d|, |%-*.*d|, |%-*.*d|, |%-*.*d|, |%-*.*d|\n\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			ft_printf("39: a: |%d| b: |%d|   ", a, b);ft_printf("|%0*.*i|, |%0*.*d|, |%0*.*d|, |%0*.*d|, |%0*.*d|, |%0*.*d|, |%0*.*d|, |%0*.*d|\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			printf("39: a: |%d| b: |%d|   ", a, b);printf("|%0*.*i|, |%0*.*d|, |%0*.*d|, |%0*.*d|, |%0*.*d|, |%0*.*d|, |%0*.*d|, |%0*.*d|\n\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			b++;
		}
		a++;
	}
	a = 19;
	b = 14;
	ft_printf("40:");ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d\n", a, b, -42, a, b, 42, -a, -b, -42, -a, -b, 42, -a, b, -42, -a, b, 42, a, -b, -42, a, -b, 42); //T178
	printf("40:");printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d\n", a, b, -42, a, b, 42, -a, -b, -42, -a, -b, 42, -a, b, -42, -a, b, 42, a, -b, -42, a, -b, 42); //T178
	ft_printf("41:");ft_printf("%12.12i, %12.12d\n", -42, 42); //T179
	printf("41:");printf("%12.12i, %12.12d\n", -42, 42); //T179
	ft_printf("42:");ft_printf("%1s, %1s, %1s, %1s, %1s\n", n, o, p, q, r); //T180
	printf("42:");printf("%1s, %1s, %1s, %1s, %1s\n", n, o, p, q, r); //T180
	ft_printf("43:");ft_printf("%2s, %2s, %2s, %2s, %2s\n", n, o, p, q, r); //T181
	printf("43:");printf("%2s, %2s, %2s, %2s, %2s\n", n, o, p, q, r); //T181
	ft_printf("44:");ft_printf("%3s, %3s, %3s, %3s, %3s\n", n, o, p, q, r); //T182
	printf("44:");printf("%3s, %3s, %3s, %3s, %3s\n", n, o, p, q, r); //T182
	ft_printf("45:");ft_printf("%4s, %4s, %4s, %4s, %4s\n", n, o, p, q, r); //T183
	printf("45:");printf("%4s, %4s, %4s, %4s, %4s\n", n, o, p, q, r); //T183
	ft_printf("46:");ft_printf("%15s, %15s, %15s, %15s, %15s\n", n, o, p, q, r); //T184
	printf("46:");printf("%15s, %15s, %15s, %15s, %15s\n", n, o, p, q, r); //T184
	ft_printf("47:");ft_printf("%16s, %16s, %16s, %16s, %16s\n", n, o, p, q, r); //T185
	printf("47:");printf("%16s, %16s, %16s, %16s, %16s\n", n, o, p, q, r); //T185
	ft_printf("48:");ft_printf("%17s, %17s, %17s, %17s, %17s\n", n, o, p, q, r); //T186
	printf("48:");printf(":");printf("%17s, %17s, %17s, %17s, %17s\n", n, o, p, q, r); //T186
	ft_printf("49:");ft_printf("%.s, %.s, %.s, %.s, %.s\n", n, o, p, q, r); //T186
	printf("49:");printf("%.s, %.s, %.s, %.s, %.s\n", n, o, p, q, r); //T186
	ft_printf("50:");ft_printf("%1.s, %1.s, %1.s, %1.s, %1.s\n", n, o, p, q, r); //T186
	printf("50:");printf("%1.s, %1.s, %1.s, %1.s, %1.s\n", n, o, p, q, r); //T186
	a = -4;
	while (a < 5) //T187-213
	{
		ft_printf("51: a: |%d| b: |%d|   ", a, b);ft_printf("%*s, %*s, %*s, %*s, %*s, %*s, %*s, %*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u);
		printf("51: a: |%d| b: |%d|   ", a, b);printf("%*s, %*s, %*s, %*s, %*s, %*s, %*s, %*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u);
		ft_printf("52: a: |%d| b: |%d|   ", a, b);ft_printf("%-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u);
		printf("52: a: |%d| b: |%d|   ", a, b);printf("%-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u);
		ft_printf("53: a: |%d| b: |%d|   ", a, b);ft_printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u);
		printf("53: a: |%d| b: |%d|   ", a, b);printf("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s\n", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u);
		a++;
	}
	a = -2;
	while(a < 5) //T70-177
	{
		b = -2;
		while (b < 5)
		{
			ft_printf("54: a: |%d| b: |%d|   ", a, b);ft_printf("%*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s\n", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);
			printf("54: a: |%d| b: |%d|   ", a, b);printf("%*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s\n", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);
			ft_printf("55: a: |%d| b: |%d|   ", a, b);ft_printf("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s\n", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);
			printf("55: a: |%d| b: |%d|   ", a, b);printf("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s\n", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);
			b++;
		}
		a++;
	}
	ft_printf("56:");ft_printf("%u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X\n", i, i, i, j, j, j, k, k, k, l, l, l, m, m, m, c, c, c, d, d, d, e, e, e); //T214
	printf("56:");printf("%u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X\n", i, i, i, j, j, j, k, k, k, l, l, l, m, m, m, c, c, c, d, d, d, e, e, e); //T214
	a = -1;
	while (a < 5) //T214-256
	{
		ft_printf("57:  a: |%d|   ", a);ft_printf("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X\n", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
		printf("57:  a: |%d|   ", a);printf("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X\n", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
		ft_printf("58:  a: |%d|   ", a);ft_printf("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X\n", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
		printf("58:  a: |%d|   ", a);printf("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X\n", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
		ft_printf("59:  a: |%d|   ", a);ft_printf("%-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X\n", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
		printf("59:  a: |%d|   ", a);printf("%-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X\n", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
		ft_printf("60:  a: |%d|   ", a);ft_printf("%.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X\n", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
		printf("60:  a: |%d|   ", a);printf("%.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X\n", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
		a++;
	}
	a = -1;
	while(a < 5) //T257-346
	{
		b = -1;
		while (b < 5)
		{
			ft_printf("61: a: |%d| b: |%d|   ", a, b);ft_printf("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
			printf("61: a: |%d| b: |%d|   ", a, b);printf("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
			ft_printf("62: a: |%d| b: |%d|   ", a, b);ft_printf("%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
			printf("62: a: |%d| b: |%d|   ", a, b);printf("%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
			ft_printf("63: a: |%d| b: |%d|   ", a, b);ft_printf("%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
			printf("63: a: |%d| b: |%d|   ", a, b);printf("%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
			b++;
		}
		a++;
	}
	ft_printf("64:");ft_printf("%p, %x, %p, %x, %p, %x, %p, %x\n", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0); //T347
	printf("64:");printf("%p, %x, %p, %x, %p, %x, %p, %x\n", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0); //T347
	a = 8;
	while (a < 12) //
	{
		ft_printf("65:");ft_printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
		printf("65:");printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
		ft_printf("66:");ft_printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
		printf("66:");printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
		a++;
	}
	a = f;
	b = g;
	ft_printf("67:");ft_printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c);
	printf("67:");printf("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d\n", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c);
	ft_printf("68:");ft_printf("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s\n", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);
	printf("68:");printf("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s\n", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);
	ft_printf("69:");ft_printf("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
	printf("69:");printf("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X\n", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
	ft_printf("70:");ft_printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	printf("70:");printf("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x\n", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);

	a = 12;
	b = 18;
	//ft_printf("71:");ft_printf("|%c|,  |%-c|, |%1c|, |%*c|,  |%-*c|,  |%*c|, |%-*c|\n", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c);
	//printf("71:");printf("|%c|,  |%-c|, |%1c|, |%*c|,  |%-*c|,  |%*c|, |%-*c|\n\n", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c);
	//ft_printf("72:");ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c\n", c, n[0], o[0], -a, p[0], -a, q[0], -a, r[0], -a, c);
	//printf("72:");printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c\n", c, n[0], o[0], -a, p[0], -a, q[0], -a, r[0], -a, c);
	//ft_printf("73:");ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c\n", c, n[0], q[0], a, q[0], a, p[0], a, p[0], a, c);
	//printf("73:");printf("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c\n", c, n[0], q[0], a, q[0], a, p[0], a, p[0], a, c);
	//ft_printf("74:");ft_printf("%c,  %-c, %1c, %*c,  %-*c,  %*c\n", -12, -1, -255, a, -12, a, -1, a, -255);
	//printf("74:");printf("%c,  %-c, %1c, %*c,  %-*c,  %*c\n", -12, -1, -255, a, -12, a, -1, a, -255);
	//ft_printf("75:");ft_printf("%%, \t, \\, \", \', +\n");
	printf("75:");printf("%%, \t, \\, \", \', +\n");
	ft_printf("76:");ft_printf("%%%dbada%s%%**%s**-d%%0*d%-12s0*@\n", h, "bada", r, p, r, r, i, r, i, r, i);
	printf("76:");printf("%%%dbada%s%%**%s**-d%%0*d%-12s0*@\n", h, "bada", r, p, r, r, i, r, i, r, i);
	ft_printf("77:");ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d\n", a, i, a, i, a, i, a, i, a, i);
	printf("77:");printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d\n\n", a, i, a, i, a, i, a, i, a, i);
	ft_printf("78:");ft_printf("|%-00000-----*i|, |%---0.*d|, |%0-0-0-0--0.*d|, |%-0-0-0-0-.*d|, |%-----.*d|\n", a, j, a, j, a, j, a, j, a, j);
	printf("78:");printf("|%-00000-----*i|, |%---0.*d|, |%0-0-0-0-0.*d|, |%-0-0-0-0-.*d|, |%-----.*d|\n\n", a, j, a, j, a, j, a, j, a, j);
	ft_printf("79:");ft_printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d\n", a, l, a, l, a, l, a, l, a, l);
	printf("79:");printf("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d\n", a, l, a, l, a, l, a, l, a, l);
	ft_printf("80:");ft_printf("%i, %d, %d, %d, %d, %d, %u, %x, %X\n", 0, 0, 0, 0, 0, 0, 0, 0, 0);
	printf("80:");printf("%i, %d, %d, %d, %d, %d, %u, %x, %X\n", 0, 0, 0, 0, 0, 0, 0, 0, 0);
	ft_printf("81:");ft_printf("%*i, %*d, %*d, %*d, %*d, %*d, %*u, %*x, %*X\n", a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0);
	printf("81:");printf("%*i, %*d, %*d, %*d, %*d, %*d, %*u, %*x, %*X\n", a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0);
	//ft_printf("82:");ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	//printf("82:");printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	ft_printf("83:");ft_printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL);
	printf("83:");printf("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL);
	// ^ Theoriquement un comportement indefini mais testé par la moulinette
    ft_printf("84:");ft_printf("(null)\n");
    printf("84:");printf("(null)\n");
	ft_printf("85:");ft_printf("\n");
	printf("85:");printf("\n");*/
}