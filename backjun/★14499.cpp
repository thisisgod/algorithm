//주사위 굴리기 시뮬레이션 A
#include<iostream>
using namespace std;

int n, m, x, y, k,direct,num;
int arr[20][20];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct dice {
	int row[3];
	int cols[4];
};

dice d;
void diceroll(int dir) {
	if (dir < 2)
	{
		if (x + dx[dir] >= m || x + dx[dir] < 0)return;
		x += dx[dir];
		int tmp = d.row[1-dx[dir]];
		if(dir==0)for (int i = 4; i < 7; i++)d.row[(i - dx[dir]) % 3] = d.row[i % 3];
		else for (int i = 4; i > 2; i--)d.row[(i - dx[dir]) % 3] = d.row[i % 3];
		d.row[(4 - dx[dir] - dx[dir])%3] = tmp;
		if (dir == 0)
		{
			int tmp = d.row[2];
			d.row[2] = d.cols[3];
			d.cols[3] = tmp;
		}
		else
		{
			int tmp = d.row[0];
			d.row[0] = d.cols[3];
			d.cols[3] = tmp;
		}
		if (!arr[y][x])arr[y][x] = d.row[1];
		else
		{
			d.row[1] = arr[y][x];
			arr[y][x] = 0;
		}
		d.cols[1] = d.row[1];
		cout << d.cols[3] << "\n";
	}
	else
	{
		if (y + dy[dir] >= n || y + dy[dir] < 0)return;
		y += dy[dir];
		int tmp = d.cols[1-dy[dir]];
		if (dir == 3)for (int i = 5; i < 8; i++)d.cols[(i - dy[dir]) % 4] = d.cols[i % 4];
		else for (int i = 5; i >2; i--)d.cols[(i - dy[dir]) % 4] = d.cols[i % 4];
		d.cols[(5 - dy[dir] - dy[dir])%4] = tmp;
		if (!arr[y][x])arr[y][x] = d.cols[1];
		else
		{
			d.cols[1] = arr[y][x];
			arr[y][x] = 0;
		}
		d.row[1] = d.cols[1];
		cout << d.cols[3] << "\n";
	}
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);
	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> arr[i][j];
	for (int inp = 0; inp < k; inp++)
	{
		cin >> direct;
		diceroll(direct - 1);
	}
	return 0;
}
