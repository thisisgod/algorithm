//안전 영역 20190218 DFS 만족스럽지 못하니 다시 풀어볼것
#include<iostream>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

int n,cnt,k,result;
int map[101][101];
int arr[101];
bool check[101][101];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool exception_handling(int one, int two, int type)
{
	if (type < 2)
	{
		if (one + dx[type] > -1 && one + dx[type] < n)return true;
		else return false;
	}
	else
	{
		if (dy[type] + two > -1 && dy[type] + two < n)return true;
		else return false;
	}
}

void dfs(int curY,int curX,int hei)
{
	check[curY][curX] = true;
	f(z,0,4)if(exception_handling(curX,curY,z))if(!check[curY+dy[z]][curX+dx[z]]&&map[curY + dy[z]][curX + dx[z]] >hei) dfs(curY+dy[z],curX+dx[z],hei);
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	cin >> n;
	result = 1;

	f(i, 0, n)f(j, 0, n)
	{
		cin >> map[i][j];
		k = k > map[i][j] ? k : map[i][j];
	}
	f(h, 1, k+1)
	{
		cnt = 0;
		f(i, 0, n)
		{
			f(j, 0, n)
			{
				if (!check[i][j] && map[i][j] > h)
				{
					dfs(i, j, h);
					cnt++;
				}
			}
		}
		f(i, 0, n)f(j, 0, n)check[i][j] = 0;
		result = result > cnt ? result : cnt;
	}
	cout << result;
}
