//영역 구하기 20190215 DFS
#include<iostream>
#include<algorithm>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

int n,m,k,cnt;
bool map[100][100];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int arr[5000];

bool compare(const int &a, const int &b)
{
	return a < b;
}

bool exception_handling(int one, int two, int type)
{
	if (type < 2)
	{
		if (one + dx[type] > -1 && one + dx[type] < n)return true;
		else return false;
	}
	else
	{
		if (dy[type] + two > -1 && dy[type] + two < m)return true;
		else return false;
	}
}


int dfs(int curY,int curX)
{
	map[curY][curX] = true;
	int ret = 1;
	f(z, 0, 4) if(exception_handling(curX,curY,z)) if (!map[curY + dy[z]][curX + dx[z]]) ret += dfs(curY + dy[z], curX + dx[z]);
	return ret;
}

int main()
{
	cin >> n >> m >> k;
	int a, b, c, d;
	f(i, 0, k)
	{
		cin >> a >> b >> c >> d;
		f(j, a, c)f(z, b, d)map[j][z] = true;
	}
	f(i, 0, m)f(j, 0, n)if (!map[i][j])arr[cnt++] = dfs(i, j);
	cout << cnt<<"\n";
	sort(arr, arr + cnt,compare);
	f(i, 0, cnt)cout << arr[i]<<" ";
}
