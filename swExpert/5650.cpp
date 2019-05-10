//핀볼 게임 시뮬레이션
#include<iostream>
using namespace std;

int n,t,score,highscore;
int map[100][100];
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };//0 r 1 d 2 l 3 u

struct hole {
	int x[2], y[2];
	int cnt;
};

hole h[6];

int game(int y,int x,int dir)
{
	int ret = 0;
	int j=x, i=y;
	while (1)
	{
		if (i + dy[dir] >= n || i + dy[dir] < 0 || j + dx[dir] >= n || j + dx[dir] < 0)
		{
			dir = (dir + 2) % 4;
			ret++;
			if (y == i && x == j)return ret;
		}
		else
		{
			j += dx[dir], i += dy[dir];
			if (y == i && x == j)return ret;
		}
		if (map[i][j] == -1)return ret;
		else if (!map[i][j])continue;
		else if (map[i][j] == 1)
		{
			if (dir == 0 || dir==3)dir = (dir + 2) % 4;
			else if (dir == 2)dir++;
			else if (dir == 1)dir--;
			ret++;
		}
		else if (map[i][j] == 2)
		{
			if (dir == 0 || dir == 1)dir = (dir + 2) % 4;
			else if (dir == 3)dir = 0;
			else if (dir == 2)dir--;
			ret++;
		}
		else if (map[i][j] == 3)
		{
			if (dir == 1 || dir == 2)dir = (dir + 2) % 4;
			else if (dir == 0)dir++;
			else if (dir == 3)dir--;
			ret++;
		}
		else if (map[i][j] == 4)
		{
			if (dir == 2 || dir == 3)dir = (dir + 2) % 4;
			else if (dir == 0)dir = 3;
			else if (dir == 1)dir++;
			ret++;
		}
		else if (map[i][j] == 5)
		{
			dir = (dir + 2) % 4;
			ret++;
		}
		else if (map[i][j] && map[i][j] <= 10)
		{
			int z;
			for (z = 0; z < 2; z++)
			{
				if (h[map[i][j] - 6].x[z] == j && h[map[i][j] - 6].y[z] == i)z = (z + 1) % 2;
				break;
			}
			int tmpi = h[map[i][j] - 6].y[z], tmpj = h[map[i][j] - 6].x[z];
			i = tmpi, j = tmpj;
		}
	}
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);
	cin >> t;
	for (int test = 1; test <= t; test++)
	{
		highscore = 0;
		cout << "#"<<test << " ";
		cin >> n;
		for (int y = 0; y < n; y++)for (int x = 0; x < n; x++)
		{
			cin >> map[y][x];
			if (map[y][x] >= 6 && map[y][x] <= 10)
			{
				h[map[y][x] - 6].x[h[map[y][x]-6].cnt%2] = x;
				h[map[y][x] - 6].y[h[map[y][x]-6].cnt%2] = y;
				h[map[y][x] - 6].cnt++;
			}
		}
		for (int y = 0; y < n; y++)for (int x = 0; x < n; x++)if (!map[y][x])for (int dir = 0; dir < 4; dir++)
		{
			score = game(y, x, dir);
			highscore = score > highscore ? score : highscore;
		}
		cout << highscore << "\n";
	}
}
