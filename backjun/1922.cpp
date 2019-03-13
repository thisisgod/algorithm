//네트워크 연결 20190314 프림
#include<iostream>
#include<algorithm>
using namespace std;
#define INF 10001

int n, m, a, b, c,cnt=1;
int map[1001][1001];

struct line {
	int x, y,data=INF;
};

line heap[100000];

void push(line inp)
{
	if (cnt==1)heap[cnt++] = inp;
	else
	{
		heap[cnt] = inp;
		for (int i = cnt++; i > 1; i /= 2)
		{
			if (heap[i].data < heap[i / 2].data)
			{
				line tmp = heap[i];
				heap[i] = heap[i / 2];
				heap[i / 2] = tmp;
			}
			else break;
		}
	}
}

int swap(int f, int s)
{
	line tmp = heap[f];
	heap[f] = heap[s];
	heap[s] = tmp;
	return s;
}

line pop()
{
	line ret = heap[1];
	heap[1] = heap[cnt - 1];
	heap[cnt - 1].data = INF;
	cnt--;
	for (int i = 1; i < cnt - 1;)
	{
		if (heap[i].data > heap[i * 2].data&&heap[i].data > heap[i * 2 + 1].data) 
			i = heap[i * 2].data > heap[i * 2 + 1].data? swap(i, i * 2 + 1):swap(i, i * 2);
		else if (heap[i].data > heap[i * 2].data)i = swap(i, i * 2);
		else if (heap[i].data > heap[i * 2 + 1].data)i = swap(i, i * 2 + 1);
		else break;
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
		tmp1.x = a;
		tmp1.y = b;
		tmp1.data = c;
		push(tmp1);
	}
	int a = 1;
	pop();
 	pop();
	pop();
}
