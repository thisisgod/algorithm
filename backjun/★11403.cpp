//경로찾기 20190218 DFS (DP로 푸는게 더 빠르니 DP로도 풀어 볼 것)
#include<iostream>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

int n,cnt;
int map[101][101];
bool check[101];

void dfs(int curY)
{
	check[curY] = true;
	f(i, 0, n)
		if (!check[i] && map[curY][i])
		{
			dfs(i);
			f(j, 0, n)if (map[i][j])map[curY][j] = 1;
		}
		else if (check[i] && map[curY][i])f(j,0,n)if(map[i][j])map[curY][j] = 1;
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	cin >> n;

	f(i, 0, n)f(j, 0, n)cin >> map[i][j];
	f(i,0,n)dfs(i);
	f(i, 0, n)
	{
		f(j, 0, n) cout << map[i][j] << " ";
		cout << "\n";
	}
}
