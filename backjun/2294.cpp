//동전 2 20190114 DP(기초)
#include<iostream>
#include<algorithm>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

int cache[10001];
int arr[10001];
int n,k;

int coin(int sum)
{
	if (sum == k)return 0;
	if (sum > k)return 987654321;

	int &ret = cache[sum];
	if (ret != -1)return ret;
	ret = coin(sum + arr[0]) + 1;

	f(i, 1, n) ret = min(ret, coin(sum + arr[i]) + 1);
	return ret;
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	cin >> n >> k;
	f(inp, 0, n) cin>>arr[inp];
	fill(cache, cache + k + 1, -1);
	int result = coin(0);
	cout << (result > k ? -1 : result);
}
