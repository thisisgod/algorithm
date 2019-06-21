#include<stdio.h>
#define _USE_MATH_DEFINES
#include<math.h>

struct square {
	int right;
	int left;
	int height;
}sq;

square sarr[1000];
int t,r,s,e,n;
double ret;

int main()
{
	scanf("%d", &t);
	for (register int test = 1; test <= t; test++)
	{
		ret = 0;
		scanf("%d %d %d %d", &r, &s, &e, &n);
		for (register int inp = 0; inp < n; inp++) scanf("%d %d %d", &sarr[inp].left, &sarr[inp].right, &sarr[inp].height);
		ret += sarr[0].left - r - s;
		ret += e - sarr[n - 1].right - r;
		for (register int i = 0; i < n; i++)
		{
			if (sarr[i].height >= r)
			{
				ret += 2 * sarr[i].height - 2 * r + sarr[i].right - sarr[i].left + M_PI * r;
			}
			else
			{
				ret += acos(((double)(r - sarr[i].height) / r))* 2 * r; 
				ret += sarr[i].right - sarr[i].left;
				ret += 2 * (r - sqrt(2 * r*sarr[i].height - sarr[i].height*sarr[i].height));
			}
			if (i != n - 1)ret += sarr[i + 1].left - sarr[i].right - 2 * r;
		}
		printf("Case #%d\n%.10lf\n",test, ret);
	}
}
