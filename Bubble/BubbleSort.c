#include <stdio.h>

int main()
{
	int num[6] = { 23,9,71,31,116,48 };
	int temp;

	for (int i = 0; i < 6; i++)
	{
		printf("%d ", num[i]);
	}

	printf("\n");

	for (int i = 1; i <= 6; i++)
	{
		for (int j = 1; j <= 6 - i; j++)
		{
			if (num[j - 1] > num[j])
			{
				temp = num[j - 1];
				num[j - 1] = num[j];
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