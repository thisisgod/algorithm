#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

struct point {
	int x, y;
};

point arr[20000];
vector<int> index;

double dir(point a,point b,point c)
{
	double ret = a.x*b.y + b.x*c.y + c.x*a.y - a.y*c.x - b.y*a.x - c.y*b.x;
	return ret > 0 ? 1 : ret == 0 ? 0 : -1;
}

void swap1(int a,int b)
{
	point tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void q_sort(int first,int second)
{
	if (first >= second)return;

	point a, b;
	a = arr[first];
	b = arr[second / 2];
	int i , j;
	for (int i = 1, j = second; i < j;)
	{
		if (dir(a, b, arr[i]) > 0)i++;
		else if (dir(a, b, arr[j]) < 0)j--;
		else swap1(arr[i], arr[j]);
	}
	swap(arr[j], b);
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);


}
