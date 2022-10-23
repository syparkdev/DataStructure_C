#include <stdio.h>

int main()
{
	int num[6] = { 23, 9, 71, 31, 116, 48 };
	int min_index, temp;

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", num[i]);
	}

	printf("\n");

	for (int i = 0; i < 6; i++)
	{
		min_index = i;

		for (int j = i; j < 6; j++)
		{
			if (num[j] < num[min_index])
			{
				min_index = j;
			}
		}

		temp = num[i];
		num[i] = num[min_index];
		num[min_index] = temp;

		for (int i = 0; i < 6; i++)
		{
			printf("%d ", num[i]);
		}

		printf("\n");
	}

	return 0;
}