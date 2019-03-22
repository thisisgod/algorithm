#include<iostream>//90
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define INF 99999

int n, k, a, b;
int dx[8] = { 0,0,10001,-10001,10001,10001,-10001,-10001};
int dy[8] = { 10001,-10001,0,0,10001,-10001,10001,-10001};

class point {
public:
	int x, y;
	point(int a, int b)
	{
		this->x = a;
		this->y = b;
	}
};

vector<point> pos;

int direction(point a, point b, point c)
{
	long long int ret = b.x*a.y + c.x*b.y + a.x*c.y - c.x*a.y - b.x*c.y - a.x*b.y;
	return ret < 0 ? -1 : ret == 0 ? 0 : 1;
}

bool point_in_box(point a, point b, point c)
{
	return (min(a.x, b.x) <= c.x&&max(a.x, b.x) >= c.x&&min(a.y, b.y) <= c.y&&max(a.y, b.y) >= c.y);
}

int point_in_polygon(point a)
{
	int ret = INF, icnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (direction(pos[i], pos[i + 1], a) == 0 && point_in_box(pos[i], pos[i + 1], a))return 1;
	}
	for (int i = 0; i < 8; i++)
	{
		int cnt = icnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (direction(pos[j], pos[j + 1], point(a.x + dx[i], a.y + dy[i]))*direction(pos[j], pos[j + 1], a) < 0)
			{
				if (direction(a, point(a.x + dx[i], a.y + dy[i]), pos[j])*direction(a, point(a.x + dx[i], a.y + dy[i]), pos[j + 1]) < 0)cnt++;
				else if ((direction(a, point(a.x + dx[i], a.y + dy[i]), pos[j]) == 0 && point_in_box(a, point(a.x + dx[i], a.y + dy[i]), pos[j])) || (direction(a, point(a.x + dx[i], a.y + dy[i]), pos[j + 1]) == 0 && point_in_box(a, point(a.x + dx[i], a.y + dy[i]), pos[j + 1]))) icnt++;
			}
			else if ((direction(a, point(a.x + dx[i], a.y + dy[i]), pos[j]) == 0 && point_in_box(a, point(a.x + dx[i], a.y + dy[i]), pos[j])) && (direction(a, point(a.x + dx[i], a.y + dy[i]), pos[j + 1]) == 0 && point_in_box(a, point(a.x + dx[i], a.y + dy[i]), pos[j + 1])))cnt++;
		}
		ret = min(ret, cnt + icnt / 2);
	}
	return ret % 2;
}

int main()
{
	freopen("point.inp", "r", stdin);
	freopen("point.out", "w", stdout);
	cin >> n;
	for (int inp = 0; inp < n; inp++)
	{
		cin >> a >> b;
		pos.push_back(point(a, b));
	}
	pos.push_back(pos.front());
	cin >> k;
	for (int inp = 0; inp < k; inp++)
	{
		cin >> a >> b;
		cout << point_in_polygon(point(a, b)) << "\n";
	}
}
