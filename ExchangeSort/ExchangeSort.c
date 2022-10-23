#include <stdio.h>

int main()
{
	int num[6] = { 23,9,71,31,116,48 };
	int i, j, temp;

	for (i = 0; i < 5; i++)
	{
		for (j = i + 1; j < 6; j++)
		{
			if (num[i] > num[j])
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
		for (int i = 0; i < 6; i++)
		{
			printf("%d ", num[i]);
		}

		printf("\n");
	}

	return 0;
}