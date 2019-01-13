//분해합 20190108 
#include<iostream>
using namespace std;
#define f(i,n) for(int i=1;i<=n;i++)

int main()
{
	freopen("input.inp", "r", stdin);
	freopen("out.out", "w", stdout);
	
	int n;
	cin >> n;
	int sum;

	f(i, n)
	{
		sum = i % 10;
		for (int j = 10; j <= i; j *= 10)
		{
			sum += (i / j) % 10;
		}
		sum += i;
		if (sum == n)
		{
			cout << i;
			return 0;
		}
	}
	cout << "0";
}
