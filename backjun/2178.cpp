//미로 탐색 20190228 BFS
#include<iostream>
using namespace std;

int que[10000];
char map[10200];
int front,back;
int n, m,result;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void push(int num)
{
	que[(front++)%10000] = num;
}

int pop()
{
	return que[(back++)%10000];
}

bool empty()
{
	return (front%10000) == (back%10000);
}

int size()
{
	return ((front % 10000) - (back % 10000)+10000)%10000;// front%10000이 back%10000보다 크면 안되니까 
}

int bfs()
{
	int ret = 2,cur,qsize;
	push(1 * (m + 1) + 1);
	map[1 * (m + 1) + 1] = '0';
	while(!empty())
	{
		qsize = size();
		for (int i = 0; i < qsize; i++)
		{
			cur = pop();
			for (int z = 0; z < 4; z++)
			{
				if (dx[z] + cur < 0 || dy[z] + cur < 0 || dx[z] + cur>(n+1)*(m + 1) || dy[z] + cur>(n+1)*(m + 2))continue;
				if (map[cur + dx[z] + dy[z]]=='1')
				{
					if (cur + dx[z] + dy[z] == (n+1) * (m + 1) - 1)return ret;
					push(cur + dx[z] + dy[z]);
					map[cur+dx[z]+dy[z]] = '0';
				}
			}
		}
		ret++;
	}
	return -1;
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);
	cin >> n >> m;
	dy[2] = m + 1;
	dy[3] = -dy[2];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i*(m+1)+j];
		}
	}
	cout << bfs();
}
