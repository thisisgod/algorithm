#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int n, m;
int resourceMax[50];
int resourceNow[50];
struct process {
	int MAX[50], ALLOCATION[50], NEED[50];
};

struct request {
	int ProcessNum;
	int Resource[50];
}rq;

queue <request> q;

process p[50];

bool Request(request r) 
{
	int resourceClone[50], check[50], checkcnt = 0;
	for (int i = 0; i < m; i++)resourceClone[i] = resourceNow[i];
	for (int i = 0; i < n; i++)check[i] = 0;
	for (int i = 0; i < m; i++)
	{
		resourceClone[i] -= r.Resource[i];
		if (r.Resource[i] > p[r.ProcessNum].NEED[i])return false;
		if (resourceClone[i] < 0)
		{
			q.push(r);
			return false;
		}
	}
	for (int i = 0; i < n; i++)
	{
		int tmp = checkcnt;
		for (int z = 0; z < n; z++)
		{
			int lowcnt = 0;
			for (int j = 0; j < m; j++)
			{
				if (z == r.ProcessNum&&resourceClone[j] >= p[z].NEED[j] - r.Resource[j])lowcnt++;
				else if (resourceClone[j] >= p[z].NEED[j])lowcnt++;
			}
			if (lowcnt == m && !check[z])
			{
				for (int j = 0; j < m; j++)
				{
					resourceClone[j] += (z == r.ProcessNum ? p[z].ALLOCATION[j] + r.Resource[j] : p[z].ALLOCATION[j]);
					if (resourceClone[j] > resourceMax[j])return false;
				}
				check[z]++;
				checkcnt++;
			}
		}
		if (checkcnt == n)break;
		if (tmp == checkcnt)
		{
			q.push(r);
			return false;
		}
	}
	if (checkcnt != n)
	{
		q.push(r);
		return false;
	}
	for (int i = 0; i < m; i++)
	{
		resourceNow[i] -= r.Resource[i];
		p[r.ProcessNum].ALLOCATION[i] += r.Resource[i];
		p[r.ProcessNum].NEED[i] -= r.Resource[i]; 
	}
	return true;
}

void Release(request r)
{
	int qf,coin=1;
	for (int i = 0; i < m; i++)
	{
		resourceNow[i] += r.Resource[i];
		p[r.ProcessNum].ALLOCATION[i] -= r.Resource[i];
		p[r.ProcessNum].NEED[i] += r.Resource[i];
	}
	for (int j = 0; j < coin; j++)
	{
		qf = q.size();
		for (int i = 0;i<qf; i++)
		{
			request r1 = q.front();
			q.pop();
			if (Request(r1))coin++;
		}
	}
}

int main()
{
	freopen("banker.inp", "r", stdin);
	freopen("banker.out", "w", stdout);
	
	cin >> n >> m; 
	for (int inp2 = 0; inp2 < m; inp2++)
	{
		cin >> resourceMax[inp2];
		resourceNow[inp2] = resourceMax[inp2];
	}
	for (int inp1 = 0; inp1 < n; inp1++)for (int inp2 = 0; inp2 < m; inp2++)cin >> p[inp1].MAX[inp2];
	for (int inp1 = 0; inp1 < n; inp1++)for (int inp2 = 0; inp2 < m; inp2++)
	{
		cin >> p[inp1].ALLOCATION[inp2];
		resourceNow[inp2] -= p[inp1].ALLOCATION[inp2];
		p[inp1].NEED[inp2] = p[inp1].MAX[inp2] - p[inp1].ALLOCATION[inp2];
	}
	char str[8];
	cin >> str;
	while (str[0] != 'q')
	{
		int type = 0;
		cin >> rq.ProcessNum;
		for (int inp2 = 0; inp2 < m; inp2++)cin >> rq.Resource[inp2];
		if (!(strcmp(str, "request")))
		{
			for (int i = 0; i < m; i++)if (rq.Resource[i] > p[rq.ProcessNum].NEED[i])type = 1;
			if (!type)Request(rq);
		}
		if (!(strcmp(str, "release")))
		{
			for (int i = 0; i < m; i++)if (rq.Resource[i]>p[rq.ProcessNum].ALLOCATION[i])type = 1;
			if(!type)Release(rq);
		}
		cin >> str;
		for (int out = 0; out < m; out++)cout << resourceNow[out] << (out==m-1?"\n":" ");
	}
}
