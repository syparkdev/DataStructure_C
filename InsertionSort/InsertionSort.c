#include <stdio.h>

int main()
{
	int num[6] = { 23,9,71,31,116,48 };
	int i, j, temp;

	for (i = 0; i < 5; i++)
	{
		j = i;
		while (num[j] > num[j + 1])
		{
			temp = num[j];
			num[j] = num[j + 1];
			num[j + 1] = temp;
			j--;
		}

		for (int i = 0; i < 6; i++)
		{
			printf("%d ", num[i]);
		}

		printf("\n");
	}

	return 0;
}