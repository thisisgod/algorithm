//유기농 배추 20190212 DFS지만 어쩌라는지 모르겠어서 일단 완전탐색으로 풀었음.
#include<iostream>
#include<vector>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

int n,m,k,cnt;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int arr[50][50];
bool check[50][50];

bool exception_handling(int one, int two, int type)
{
	if (type<2)
	{
		if (one + dx[type] > -1 && one + dx[type] < m)return true;
		else return false;
	}
	else
	{
		if (dy[type] + two > -1 && dy[type] + two < n)return true;
		else return false;
	}
}

void solve(int x,int y)
{
	f(i, 0, 4)
	{
		if (exception_handling(x, y, i))
			if (arr[y+dy[i]][x+dx[i]] && !check[y+dy[i]][x+dx[i]])
			{
				check[y + dy[i]][x + dx[i]] = true;
				solve(x + dx[i], y + dy[i]);
			}
	}
}


int main()
{

	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	int t,x,y;
	cin >> t;

	f(test, 0, t)
	{
		cin >> m >> n >> k;
		
		cnt = 0;
		f(i, 0, n)f(j, 0, m)
		{
			arr[i][j] = 0;
			check[i][j] = false;
		}

		f(j, 0, k)
		{
			cin >> x >> y;
			arr[y][x] = 1;
		}
		f(i, 0, n)f(j, 0, m)
		{
			if (arr[i][j] && !check[i][j])
			{
				check[i][j] = true;
				solve(j, i);
				cnt++;
			}
		}
		cout << cnt<<"\n";
	}
}
