//부분집합의 합 20190113 1182
#include<iostream>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

int arr[20];
int N,S,result;

int bruteforce(int currentNum,int index)
{
	if (index == N)return 0;
	int ret = 0;
	f(i, index, N)
	{
		ret += bruteforce(currentNum + arr[i], i + 1);
		if (currentNum + arr[i] == S)
		ret++;
	}
	return ret;
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	cin >> N >> S;
	f(i, 0, N) cin >> arr[i];

	result = bruteforce(0, 0);

	cout << result;
}
