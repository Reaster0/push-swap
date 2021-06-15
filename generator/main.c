#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char **argv)
{
	if (!argv[1])
		return (0);
	srand(time(NULL));
	int nbr = atoi(argv[1]);
	while (nbr)
	{
		printf("%d ",rand());
		nbr--;
	}
	return (0);
}