//단지번호붙이기 20190215 DFS
#include<iostream>
#include<algorithm>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

int n,cnt;
char map[26][26];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int arr[320];

bool compare(const int &a, const int &b)
{
	return a < b;
}

int dfs(int curY,int curX)
{
	map[curY][curX] = '0';
	int ret = 1;
	f(z, 0, 4) if (map[curY + dy[z]][curX + dx[z]]=='1') ret += dfs(curY + dy[z], curX + dx[z]);
	return ret;
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	cin >> n;

	f(i, 1, n + 1)f(j, 1, n + 1)cin >> map[i][j];

	f(i, 1, n + 1)f(j, 1, n + 1)if (map[i][j]=='1')arr[cnt++] = dfs(i, j);
	cout << cnt<<"\n";
	sort(arr, arr + cnt,compare);
	f(i, 0, cnt)cout << arr[i]<<"\n";
}
