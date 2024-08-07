#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	main(void)
{
	char	c;

	c = "g";

	write (1, "g", 1);
	write (1, &c, 1);
	ft_putchar(c);
}
