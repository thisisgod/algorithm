//사람 네트워크 2 20190403 BFS
#include<iostream>
using namespace std;
#define MAXN 1000

int t, n,a,b,min_ret;
int map[1005][1005];
int msize[1005];
int check[1005];

struct queue
{
	int data[MAXN];
	int f, r;

	void init() { f = r = 0; }
	void push(int a) { data[r++] = a; }
	int pop() { return data[f++]; }
	bool empty() { return !(f < r); }
}q;

int min_row(int start)
{
	memset(check, -1, sizeof(check));
	q.init(),q.push(start),check[start]=0;
	int cur,next,ret=0;
	while (!q.empty())
	{
		cur = q.pop();
		for (register int i = 0; i < msize[cur]; i++)
		{
			next = map[cur][i];
			if (check[next]!=-1)continue;
			check[next] = check[cur]+1;
			ret += check[next];
			if (ret >= min_ret)return ret;
			q.push(next);
		}
	}
	return ret;
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);
	cin >> t;
	for (register int test = 1; test <= t; test++)
	{
		cin >> n;
		min_ret = 987654321;
		memset(msize, 0, sizeof(msize));
		memset(map, 0, sizeof(map));
		for (register int inp = 0; inp < n; inp++)
		{
			for (register int inp1 = 0; inp1 < n; inp1++)
			{
				cin >> a;
				if (a)map[inp][msize[inp]++] = inp1;
			}
		}
		for (register int i = 0; i < n; i++)
		{
			int ret = min_row(i);
			if (min_ret > ret)min_ret = ret;
		}
		cout << "#" << test << " " << min_ret << "\n";
	}
}
