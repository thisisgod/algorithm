//score 29
#include<stdio.h>
#include<algorithm>
using namespace std;

int t,a,b,z,ret;
int cache[10001];

int main()
{
	setbuf(stdout, NULL);
	scanf("%d", &t);
	for (register int i = 0; i < 10001; i++)
	{
		z = i;
		for (register int j = 1;; j++)
		{
			z = z + j;
			if (z > 10000)break;
			if(cache[z])cache[z] = min(cache[z], cache[i] + j);
			else cache[z] = cache[i] + j;
		}
	}
	for (register int test = 1; test <= t; test++)
	{
		scanf("%d %d", &a,&b);
		ret = 0;
		for (register int i = a; i <= b; i++) ret = max(ret, cache[i]);
		printf("Case #%d\n%d\n",test, ret);
	}
}
