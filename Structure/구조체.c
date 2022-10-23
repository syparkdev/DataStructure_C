#include <stdio.h>
#define NUMCOUNT	5

typedef struct
{
	int id;
	int num[NUMCOUNT];
	char name[20];
} MYSTRUCT;

int main()
{
	int i;
	MYSTRUCT info = { 100, {1, 2, 3, 4, 5}, "ȫ�浿" };

	printf("id : %d\n", info.id);
	for (i = 0; i < NUMCOUNT; i++)
		printf("num %d : %d\n", i+1, info.num[i]);
	printf("name : %s\n", info.name);

	return 0;
}