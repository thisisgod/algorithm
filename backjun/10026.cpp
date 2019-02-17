//적록색약 20190218 DFS
#include<iostream>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

int n,cnt;
char map[101][101];
bool check[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool exception_handling(int one, int two, int type)
{
	if (type < 2)
	{
		if (one + dx[type] > -1 && one + dx[type] < n+1)return true;
		else return false;
	}
	else
	{
		if (dy[type] + two > -1 && dy[type] + two < n+1)return true;
		else return false;
	}
}


void dfs(int curY,int curX)
{
	check[curY][curX] = true;
	f(z, 0, 4) if(exception_handling(curX,curY,z)) if (!check[curY + dy[z]][curX + dx[z]]&&map[curY+dy[z]][curX+dx[z]]==map[curY][curX]) dfs(curY + dy[z], curX + dx[z]);
	if (map[curY][curX] == 'R')map[curY][curX] = 'G';
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	cin >> n;
	f(i, 1, n + 1)
	{
		f(j, 1, n + 1)
		{
			cin >> map[i][j];
		}
	}
	f(i, 1, n + 1)f(j, 1, n + 1)if (!check[i][j])
	{
		dfs(i, j);
		cnt++;
	}
	cout << cnt << " ";
	cnt = 0;
	f(i, 1, n + 1)f(j, 1, n + 1)check[i][j] = false;
	f(i, 1, n + 1)f(j, 1, n + 1)if (!check[i][j])
	{
		dfs(i, j);
		cnt++;
	}
	cout << cnt << " ";
}
