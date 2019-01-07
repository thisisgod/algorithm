//성수의 프로그래밍 강좌 시청 20190107 D4
#include<iostream>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)

int arr[200];

int compare(const void *first, const void *second)
{
	if (*(int*)first > *(int*)second) return -1;
	else if (*(int*)first < *(int*)second) return 1;
	else return 0;
}

int main()
{
	freopen("input.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	int t, n, k;
	cin >> t;

	f (test, t)
	{
		cout << "#" << test + 1 << " ";
		cin >> n >> k;
		f (inp, n)
		{
			cin >> arr[inp];
		}
		qsort(arr, n, sizeof(int), compare);
		double sum = 0.;
		for (int i = k-1; i>=0; i--)
		{
			sum = (sum + arr[i]) / 2;
		}
		cout.precision(6);
		cout << sum << "\n";
	}
}
