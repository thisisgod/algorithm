//네트워크 연결 20190314 프림
#include<iostream>
#include<algorithm>
using namespace std;
#define INF 10001
#define Max 100000

int n, m, a, b, c,cnt=1;
int map[1001][1001];
int check[1001];

struct line {
	int x=0, y=0,data=INF;
};

line heap[Max];

line newline(int x,int y,int data)
{
	line l;
	l.x = x;
	l.y = y;
	l.data = data;
	return l;
}

int swap(int f, int s)
{
	line tmp = heap[f];
	heap[f] = heap[s];
	heap[s] = tmp;
	return s;
}

void push(line inp)
{
	if (cnt==1)heap[cnt++] = inp;
	else
	{
		heap[cnt] = inp;
		for (int i = cnt++; i > 1; i /= 2)
		{
			if (heap[i].data < heap[i / 2].data) swap(i, i/2);
			else break;
		}
	}
}

line pop()
{
	line ret = heap[1];
	cnt--;
	heap[1] = heap[cnt];
	heap[cnt].data = INF;
	for (int i = 1; i < cnt;)
	{
		if (i * 2 > Max)break;
		if (heap[i].data < heap[i * 2].data&&heap[i].data < heap[i * 2 + 1].data) break;
			i = heap[i * 2].data > heap[i * 2 + 1].data? swap(i, i * 2 + 1):swap(i, i * 2);
	}
	return ret;
}

int prim()
{
	int ret = 0;
	line cur = newline(INF, 1, 0);
	push(cur);
	for (; cnt;)
	{
		cur = pop();
		if (check[cur.y])continue;
		check[cur.y] = cur.x;
		ret += cur.data;
		for (int i = 0; i <= n; i++)if (!check[i]&&map[cur.y][i])push(newline(cur.y, i, map[cur.y][i]));
	}
	return ret;
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	cin >> n >> m;
	line tmp1;
	for (int inp = 0; inp < m; inp++)
	{
		cin >> a >> b >> c;
		map[a][b] = c;
		map[b][a] = c;
	}
	cout << prim();
	int a = 1;
}
