//20190211 히스토그램 스택이었지만 분할정복으로 풀었음 작년 12월 즈음에 풀고 푸는법 까먹었었으니 다시 
#include<iostream>
#include<algorithm>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

int n;
int arr[100001];

int histogram(int left, int right)
{
	if (left == right) return arr[left];

	int mid = (left + right) / 2;
	int ret = max(histogram(left, mid), histogram(mid + 1, right));

	int lo = mid, ro = mid + 1;
	int height = min(arr[lo], arr[ro]);
	ret = max(ret, height * 2);

	while (lo > left || ro < right)
	{
		if (ro < right && (lo == left || arr[ro + 1] > arr[lo -1]))
		{
			ro++;
			height = min(height, arr[ro]);
		}
		else
		{
			lo--;
			height = min(height, arr[lo]);
		}
		ret = max(ret, height * (ro - lo + 1));
	}

	return ret;
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);
	cin >> n;

	f(i, 1, n + 1)cin >> arr[i];
	
	cout << histogram(1, n);
}
