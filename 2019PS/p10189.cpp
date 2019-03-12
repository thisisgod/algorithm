#include<iostream>
#include<stdio.h>
using namespace std;

char map[101][101];
int n, m;
int ret[101][101];
int dx[8] = { 1,1,1,0,-1,-1,-1,0 };
int dy[8] = { 1,0,-1,1,1,0,-1,-1 };

bool exception_handling(int y, int x, int type)
{
	bool a = x + dx[type] < m;
	bool b = x + dx[type] >= 0;
	bool c = y + dy[type] < n;
	bool d = y + dy[type] >= 0;
	switch (type)
	{
	case 0:return a && c;
	case 1:return a;
	case 2:return a && d;
	case 3:return c;
	case 4:return b && c;
	case 5:return b;
	case 6:return b && d;
	case 7:return d;
	}
}

int main()
{
	freopen("p10189.inp", "r", stdin);
	freopen("p10189.out", "w", stdout);

	for (int t = 1;; t++)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)return 0;
		cout << "Field #" << t << ":\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> map[i][j];
				ret[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
			if (map[i][j] == '*')
				for (int z = 0; z < 8; z++)if (exception_handling(i, j, z))ret[i + dy[z]][j + dx[z]]++;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == '*')cout << map[i][j];
				else cout << ret[i][j];
			}
			cout << "\n";
		}
		cout << "\n";
	}
}
