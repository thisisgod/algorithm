#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int n;
int arr1[1000];
int arr2[1000];

bool compare(const int &a, const int &b)
{
	return a < b;
}

int cul(int avg,int arr[])
{
	int result = 0, tmp;
	for (int i = 0, j = n-1;;)
	{
		sort(arr, arr + n, compare);
		if (arr[j] == avg || arr[i] == avg)
		{
			break;
		}
		tmp = avg - arr[i] > arr[j] - avg?arr[j] - avg: avg - arr[i];
		arr[j] -= tmp;
		arr[i] += tmp;
		result += tmp;
	}
	return result;
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	double avg;
	int a, b;
	for (;;)
	{
		cin >> n;
		if (!n)return 0;
		avg = 0.0;
		int sum = 0;
		for (int inp = 0; inp < n; inp++)
		{
			scanf("%d.%d", &a, &b);
			arr1[inp] = a * 100 + b;
			arr2[inp] = a * 100 + b;
			sum += a * 100 + b;
		}
		avg =(double)sum/n;

		int ret;
		int ret1 = cul(floor(avg),arr1);
		int ret2 = cul(ceil(avg),arr2);
		ret = ret1 > ret2 ? ret1 : ret2;
		printf("$%d.%d%d\n", ret / 100, (ret / 10) % 10, ret % 10);
	}
}
