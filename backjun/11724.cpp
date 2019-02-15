//연결요소의 갯수 20190215 DFS
#include<iostream>
#include<vector>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

int n,m,cnt;
bool visit[1001];
bool map[1001][1001];

void dfs(int cur)
{
	f(i, 1, n + 1)
	{
		if (map[cur][i] && !visit[i])
		{
			visit[i] = true;
			dfs(i);
		}
	}
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	cin >> n >> m;
	int a, b;

	f(i, 0, m)
	{
		cin >> a >> b;
		map[a][b] = map[b][a] = true;
	}

	f(i, 1, n + 1)
	{
		if (!visit[i]) {
			visit[i] = true;
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;
}
