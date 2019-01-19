//프린터 큐 20190119 큐
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

int t,n,what,result,num;
queue<int> que;
int arr[100];
int arrcnt;

bool compare(int& a, int& b)
{
	return a > b;
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	cin >> t;
	f(test, 0, t)
	{
		arrcnt = 0;
		result = 0;
		cin >> n >> what;
		f(inp, 0, n)
		{
			cin >> arr[inp];
			que.push(arr[inp]);
		}
		sort(arr, arr + n,compare);
		for (;!que.empty();)
		{
			if (que.front() == arr[arrcnt])
			{
				if (what == 0)
				{
					cout << result + 1 << "\n";
					what = -1;
					break;
				}
				que.pop();
				arrcnt++;
				result++;
				what--;
			}
			else
			{
				que.push(que.front());
				que.pop();
				what--;
			}
			if (what == -1)what = que.size() - 1;
		}
		for (; !que.empty();)que.pop();
	}
}
