#include<stdio.h>

int t,a,b;
int cache[1000001];

int main()
{
	scanf("%d", &t);

	cache[2] = 1;
	for (register int i = 4; i < 1000001; i+=2)
	{
		cache[i] = cache[i / 2] + 1;
		cache[i - 1] = cache[i] + 1;
	}

	for (register int test = 1; test <= t; test++)
	{
		printf("Case #%d\n", test);
		scanf("%d %d", &a, &b);
		register int ret=0;
		for (register int i = a; i <= b; i++)ret += cache[i];
		printf("%d\n", ret);
	}
}
