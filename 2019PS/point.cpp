#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int n, k, a, b;

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
	int ret = 0;
	for (int i = 1; i <= n; i++) if (direction(pos[i], pos[i + 1], a) == 0 && point_in_box(pos[i], pos[i + 1], a))return 1;
	for (int j = 1; j <= n; j++)
	{
		if (direction(a, point(a.x + 20001, a.y), pos[j])*direction(a, point(a.x + 20001, a.y), pos[j + 1]) < 0)
		{
			if (direction(pos[j], pos[j + 1], point(a.x + 20001, a.y))*direction(pos[j], pos[j + 1], a) < 0)ret++;
		}
		else if (direction(a, point(a.x + 20001, a.y), pos[j]) == 0 && point_in_box(a, point(a.x + 20001, a.y), pos[j]))
		{
			if (direction(a, point(a.x + 20001, a.y), pos[j - 1])*direction(a, point(a.x + 20001, a.y), pos[j + 1]) < 0)ret++;
		}
	}
 	return ret % 2;
}

int main()
{
	freopen("point.inp", "r", stdin);
	freopen("point.out", "w", stdout);
	cin >> n;
	pos.push_back(point(0, 0));
	for (int inp = 0; inp < n; inp++)
	{
		cin >> a >> b;
		pos.push_back(point(a, b));
	}
	pos[0].x = pos[n].x;
	pos[0].y = pos[n].y;
	pos.push_back(pos[1]);
	cin >> k;
	for (int inp = 0; inp < k; inp++)
	{
		cin >> a >> b;
		cout << point_in_polygon(point(a, b)) << "\n";
	}
}
