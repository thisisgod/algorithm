//제곱수의 합 20190114 DP(기초)
#include<iostream>
#include<algorithm>
using namespace std;
#define f(i,k,n) for(int i=k;i<=n;i++)

int cache[100501];
int need[320];
int n;

int main()
{
	cin >> n;
	f(i, 1, 317)
	{
		need[i - 1] = i * i;
		cache[i*i] = 1;
		if (n == i * i)
		{
			cout << 1;
			return 0;
		}
	}
	f(i, 2, n + 1)
	{
		if (cache[i])continue;
		cache[i] = 1000;
		for (int j = 0; i - need[j] > 0; j++) cache[i] = min(cache[i], cache[i - need[j]] + 1);
	}
	cout << cache[n];
}
