#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

int		check_exist(int *tab, int n, int rand)
{
	int i = 0;

	while (i < n)
	{
		if (tab[i] == rand)
			return (0);
		i++;
	}
	return (1);
}

void    ft_putnbr(int fd, int n)
{
	long    nb;

	nb = (long)n;
	if (nb < 0)
	{
		ft_putchar(fd, '-');
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(fd, nb / 10);
	ft_putchar(fd, (nb % 10) + '0');
}

int main (int ac, char **av)
{
	int i, n, max;
	time_t t;
	int fd;
	int r;

	fd = open("tab.txt", O_RDWR | O_CREAT, 0755);
	n = atoi(av[1]);
	max = atoi(av[2]);
	if (n < max)
	{
		int tab[n];
		while (i < n)
			tab[i++] = 0;
		srand((unsigned) time(&t));
		i = 0;
		while (i < n)
		{
			r = rand() % max;
			if (i % 2 == 0)
				r = -r;
			while (check_exist(&tab[0], n, r) == 0)
			{
				r = rand() % max;
				if (i % 2 == 0)
					r = -r;
			}
			tab[i] = r;
			ft_putnbr(fd, r);
			write(fd," ",1);
			i++;
		}
	}
	else
		printf("Le nombre de valeur doir etre inferieur a la valeur max !");
	return(0);
}
