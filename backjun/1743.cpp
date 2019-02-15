//음식물 피하기 20190215 DFS
#include<iostream>
#include<algorithm>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

int n,m,k,cnt;
bool map[1001][1001];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int dfs(int curY,int curX)
{
	map[curY][curX] = false;
	int ret = 1;
	f(z, 0, 4) if (map[curY + dy[z]][curX + dx[z]]) ret += dfs(curY + dy[z], curX + dx[z]);
	return ret;
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	cin >> n >> m >> k;
	int a, b;
	
	f(i, 0, k)
	{
		cin >> a >> b;
		map[a][b] = true;
	}
	f(i, 1, n + 1)f(j, 1, m + 1)if (map[i][j])cnt = max(cnt, dfs(i,j));
	cout << cnt;
}
