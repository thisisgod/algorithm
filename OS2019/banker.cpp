#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
#define MAX 50

struct request {
	int processNum;
	int resource[5];
};

struct queue
{
	int data[MAX];
	int f, r;

	void init() { f = r = 0; }
	void push(int a) { data[r++] = a; }
	int pop() { return data[f++]; }
	bool empty() { return !(f < r); }
}q;

int n, m;//프로세스 n, 자원의 종류 m
int tmp,processnum;
int need[MAX][MAX];
int need_copy[MAX][MAX];
int allocation[MAX][MAX];
int allocation_copy[MAX][MAX];
int maxresource[MAX];
int processmax[MAX][MAX];
int current[MAX];
int current_copy[MAX];
request r[MAX];
string str;

void Alloc(int now)
{
	int i, type=0,zerocnt=0,cnt=0;
	for (i = 0; i < m&&r[now].resource[i] <= current_copy[i]; i++);
	if (i == m)
	{
		for (int j = 0; j < m; j++)current_copy[j] -= r[now].resource[j];
		for (int j = 0; j < m; j++)
		{
			allocation_copy[r[now].processNum][j] += r[now].resource[j];
			if (allocation_copy[r[now].processNum][j] == processmax[r[now].processNum][j])cnt++;
		}
		for (int j = 0; j < n;j++)
		{
			if (cnt == m && j == r[now].processNum)
			{
				for (int z = 0; z < m; z++)
				{
					current_copy[z] += allocation_copy[j][z];
					allocation_copy[j][z] = 0;
				}
				continue;
			}
			q.push(j);
		}
		while (cnt != m)
		{
			
		}
	}
	else
	{

	}
}

int main()
{
	freopen("banker.inp", "r", stdin);
	freopen("banker.out", "w", stdout);

	cin >> n >> m;
	for (int i = 0; i < m; i++)cin >> maxresource[i];
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> processmax[i][j];
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)
	{
		cin >> allocation[i][j];
		allocation_copy[i][j] = allocation[i][j];
	}
	for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)
	{
		need[i][j] = processmax[i][j] - allocation[i][j];
		need_copy[i][j] = processmax[i][j] - allocation[i][j];
	}
	getchar();
	cin >> str;
	for(int cnt=0;!str.compare("quit");cnt++)
	{
		q.init();
		cin >> r[cnt].processNum;
		for (int i = 0; i < m; i++)cin>>r[cnt].resource[i];
		if (str.compare("request"))
		{
			
		}
	}
}
