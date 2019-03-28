#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

struct point {
	int x, y;
};

point arr[20001];
vector<int> index;

double dir(point a, point b, point c)
{
	double ret = a.x*b.y + b.x*c.y + c.x*a.y - a.x*c.y - b.x*a.y - c.x*b.y;
	return ret > 0 ? 1 : ret == 0 ? 0 : -1;
}

void swap1(int a, int b)
{
	point tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void q_sort(int first, int second)
{
	if (first >= second)return;

	point a, b;
	a = arr[first];
	b = arr[second];
	int i, j;
	for (i = first+1, j = second-1; i < j;)
	{
		if (dir(a, b, arr[i]) > 0)i++;
		else if (dir(a, b, arr[j]) < 0)j--;
		else swap1(i, j);
	}
	swap1(j, second);
	q_sort(first, j);
	q_sort(j + 1, second);
}

int main()
{
	freopen("point.inp", "r", stdin);
	freopen("point.out", "w", stdout);

	int n,inp1,inp2;
	int minX=0,maxX=0;
	cin >> n;
	for (int inp = 0; inp < n; inp++)
	{
		cin >> inp1 >> inp2;
		arr[inp].x = inp1;
		arr[inp].y = inp2;
		if (arr[minX].x > arr[inp].x)minX = inp;
		else if (arr[minX].x == arr[inp].x&&arr[minX].y > arr[inp].y)minX = inp;
		if (arr[maxX].x < arr[inp].x)maxX = inp;
		else if (arr[maxX].x == arr[inp].x&&arr[maxX].y < arr[inp].y)maxX = inp;

	}
	swap1(minX, 0);
	swap1(n - 1, maxX);
	q_sort(0, n - 1);
	arr[n] = arr[0];

	int first = 0, cur=1;
	index.push_back(1);
	for (int i = 2; i <= n; i++)
	{
		if (dir(arr[first], arr[cur], arr[i]) >= 0)
		{
			index.push_back(i);
			cur = index[index.size() - 1];
			first = index[index.size() - 2];
		}
		else
		{
			cur = index.back();
			index.pop_back();
			i--;
		}
	}
	cout << index.size();
	for (int i = 0; i < index.size(); i++)
	{
		cout << index[i]<<"\n";
	}
}
