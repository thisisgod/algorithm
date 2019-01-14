//이항계수2 20190114 DP(기초)
#include<iostream>
#include<algorithm>
using namespace std;
#define f(i,k,n) for(int i=k;i<=n;i++)

int cache[1001][1001];
int N, K;

int binomial(int n, int k)
{
	if (k > n || n < 0)return 0;
	if (k == 0 || k == n)return 1;

	int &ret = cache[n][k];
	if (ret != -1)return ret;
	ret = (binomial(n - 1, k - 1))%10007 + (binomial(n - 1, k))%10007;

	return ret%10007;
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	cin >> N >> K;
	f(i, 0, N)f(j, 0, K) cache[i][j] = -1;
	cout<< binomial(N, K);
}
