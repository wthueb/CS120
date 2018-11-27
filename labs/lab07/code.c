#include <stdio.h>

int array[6] = {1, 2, 3, 4, 5, 6};

int main()
{
	int i;
	
	for (i = 0; i < 6; i = i + 1)
	{
		if (array[i] < 3)
			array[i] = array[i] + 5;
		else
			array[i] = array[i] + 7;
	}

	for (i = 0; i < 6; i = i + 1)
		printf("%d\n", array[i]);
}
