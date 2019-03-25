#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

struct circle {
	int x, y, r;
};

struct point {
	double x, y;
};

circle cir[3];
point po[3];
int t, a, b, c,cnt;

void func(circle a, circle b,circle c)
{
	double m=0, n=0, z=0, o, p, q, w, e, x1, x2, y1, y2, d1, d2;
	m = 2 * (b.x-a.x);
	n = 2 * (b.y-a.y);
	z = pow(a.x, 2) + pow(a.y, 2) + pow(b.r, 2) - pow(b.x, 2) - pow(b.y, 2) - pow(a.r, 2);
	if (a.x == b.x)
	{
		q = 1;
		w = -2 * a.x;
		e = pow(a.x, 2) + pow(-z / n, 2) + 2 * a.y*z / n + pow(a.y, 2) - pow(a.r, 2);
		x1 = (-w + sqrt(pow(w, 2) - 4 * q*e)) / (2 * q);
		x2 = (-w - sqrt(pow(w, 2) - 4 * q*e)) / (2 * q);
		y1 = y2 = -z / n;
	}
	else if (a.y == b.y)
	{
		q = 1;
		w = -2 * a.y;
		e = pow(a.y, 2) + pow(-z / m, 2) + 2 * a.x*z / m + pow(a.x, 2) - pow(a.r,2);
		x1 = x2 = -z / m;
		y1 = (-w + sqrt(pow(w, 2) - 4 * q*e)) / (2 * q);
		y2 = (-w - sqrt(pow(w, 2) - 4 * q*e)) / (2 * q);
	}
	else
	{
		o = n == 0 ? 0 : z / n;
		p = n == 0 ? 0 : -m / n;
		q = 1 + pow(p, 2);
		w = -2 * (a.x + o * p + a.y*p);
		e = pow(a.x, 2) + pow(o, 2) + 2 * a.y*o + pow(a.y, 2) - pow(a.r, 2);
		x1 = (-w + sqrt(pow(w, 2) - 4 * q*e)) / (2 * q);
		x2 = (-w - sqrt(pow(w, 2) - 4 * q*e)) / (2 * q);
		y1 = p * x1 - o;
		y2 = p * x2 - o;
	}
	d1 = pow(c.x - x1, 2) + pow(c.y - y1, 2);
	d2 = pow(c.x - x2, 2) + pow(c.y - y2, 2);
	po[cnt%3].x = d1 > d2 ? x2 : x1;
	po[(cnt++)%3].y = d1 > d2 ? y2 : y1;
}

double dir(point a, point b, point c)
{
	double ret = (a.x*b.y+b.x*c.y+c.x*a.y-a.y*b.x-c.y*a.x-b.y*c.x) / 2;
	return ret < 0 ? -ret : ret;
}

int main()
{
	freopen("area.inp", "r", stdin);
	freopen("area.out", "w", stdout);

	cin >> t;
	for (int test = 0; test < t; test++)
	{
		for (int inp = 0; inp < 3; inp++)
		{
			cin >> a >> b >> c;
			cir[inp].x = a;
			cir[inp].y = b;
			cir[inp].r = c;
		}
		for(int i=0;i<3;i++)func(cir[i%3], cir[(i+1)%3], cir[(i+2)%3]);
		double ret = dir(po[0], po[1], po[2]);
		printf("%.2lf\n", ret);
	}
}
