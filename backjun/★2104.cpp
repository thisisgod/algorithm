//20190628 부분배열 고르기 분할정복 (이 문제 풀면서 정복(합병)단계의 개념을 깨우침
#include<stdio.h>
#include<algorithm>
using namespace std;

int n, arr[100000];

long long int divide(int s,int e)
{
	long long int ret;
	if (s+1 == e)return arr[s]*arr[s];
	if (s == e)return 0;

	int mid = (e + s) / 2;
	ret = max(divide(s, mid), divide(mid, e));

	int r = mid, l = mid, Min = arr[r];
	long long int result = Min;
	ret = max(ret, result*Min);
	while (r - l + 1 < e - s)
	{
		int p = l > s ? arr[l - 1] : -1;
		int q = r < e - 1 ? arr[r + 1] : -1;
		if (p >= q)
		{
			Min = min(Min, p);
			result += p;
			l--;
		}
		else
		{
			Min = min(Min, q);
			result += q;
			r++;
		}
		ret = max(ret, result*Min);
	}
	return ret;
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);
	scanf("%d",&n);
	for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
	printf("%lld", divide(0, n));
}
