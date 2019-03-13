#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int n;
double arr[1000];

bool compare(const double &a, const double &b)
{
	return a < b;
}

double cul(double avg)
{
	double result = 0, tmp;
	sort(arr, arr + n, compare);
	for (int i = 0, j = n - 1; i < j;)
	{
		if (arr[j] - arr[i] < 1)break;
		if (avg - arr[i] > arr[j] - avg)
		{
			tmp = floor(arr[j] - avg);
			result += tmp;
			arr[i] += tmp;
			arr[j] -= tmp;
			if (avg - arr[i] > 0.1)i--;
			i++;
			j--;
		}
		else if (arr[j] - avg > avg - arr[i])
		{
			tmp = floor(avg - arr[i]);
			result += tmp;
			arr[i] += tmp;
			arr[j] -= tmp;
			if (arr[j] - avg > 0.1)j++;
			j--;
			i++;
		}
		else
		{
			tmp = floor(arr[j] - avg);
			result += tmp;
			arr[i] += tmp;
			arr[j] -= tmp;
			i++;
			j--;
		}
	}
	return result;
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	double avg;
	for (;;)
	{
		cin >> n;
		if (!n)return 0;
		avg = 0.0;
		for (int inp = 0; inp < n; inp++)
		{
			cin >> arr[inp];
			arr[inp] = floor(arr[inp] * 100 + 0.5);
			avg += arr[inp];
		}
		avg /= n; / l.....a/	0o0ere0;
		int c = (int)(avg + 0.5);
		int c1 = (int)avg;

		int ret;
		if (c != c1)
		{
			ret = (int)cul(floor(avg + 0.5));
		}
		else
		{
			ret = (int)cul(floor(avg));
			ret += (int)cul(floor(avg));
		}
		printf("$%d.%d%d\n", ret / 100, (ret / 10) % 10, ret % 10);
	}
}
