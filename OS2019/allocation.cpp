#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stdio.h>
using namespace std;

struct process {
	int processnum;
	int requestTime;
	int time;
	int size;
}p;

struct memory {
	int start;
	int processnum;
	int size;
}m;

struct Time {
	int time;
	int pos;
}t;

struct cmp {
	bool operator()(Time t, Time u) {
		return t.time > u.time;
	}
};

vector<process> request;
list<memory> fit[3];
priority_queue<Time, vector<Time>, cmp>timepq;
queue<process> readyque;
list<memory> ::iterator it;
int n;

void memoryInsert(process pc, int what)
{
	memory tmp, tmp1;
	tmp.processnum = pc.processnum;
	tmp.start = it->start;
	tmp.size = pc.size;
	tmp1.processnum = -1;
	tmp1.start = tmp.start + tmp.size;
	tmp1.size = it->size - pc.size;
	it = fit[what].erase(it);
	if(tmp1.size!=0)it = fit[what].insert(it, tmp1);
	it = fit[what].insert(it, tmp);
}

void erase_and_merge(int what)
{
	memory tmp;
	tmp.processnum = -1;
	tmp.size = it->size;
	tmp.start = it->start;
	if (it != fit[what].begin())
	{
		if ((--it)->processnum == -1)
		{
			tmp.size += it->size;
			tmp.start = it->start;
			it = fit[what].erase(it);
		}
		else ++it;
	}
	if (it != fit[what].end())
	{
		if ((++it)->processnum == -1)
		{
			tmp.size += it->size;
			it = fit[what].erase(it);
			--it;
		}
		else --it;
	}
	it = fit[what].erase(it);
	fit[what].insert(it, tmp);
}

int firstfit()
{
	int type=0,cnt=0;
	while(1)
	{
		process pc;
		type = 0;
		if (cnt!=request.size()&&(timepq.empty()||request[cnt].requestTime < timepq.top().time))
		{
			pc = request[cnt++];
			for (it = fit[0].begin(); it != fit[0].end(); ++it)
			{
				if (it->processnum == -1 && it->size >= pc.size)
				{
					if (pc.processnum == n - 1)
					{
						return it->start;
					}
					t.pos = it->start, t.time = pc.requestTime + pc.time;
					timepq.push(t);
					memoryInsert(pc,0);
					type = 1;
					break;
				}
			}
			if (!type)readyque.push(pc);
		}
		else
		{
			int coin = 1; 
			Time target;
			for (int i = 0; i < coin; i++)
			{
				target = timepq.top();
				timepq.pop();
				if (target.time == timepq.top().time)coin++;
				for (it = fit[0].begin(); it != fit[0].end(); ++it)
				{
					if (target.pos == it->start)
					{
						erase_and_merge(0);
						break;
					}
				}
			}
			int qf = readyque.size();
			for (int i = 0; i < qf; i++)
			{
				pc = readyque.front();
				readyque.pop();
				type = 0;
				for (it = fit[0].begin(); it != fit[0].end(); ++it)
				{
					if (it->processnum == -1 && it->size >= pc.size)
					{
						if (pc.processnum == n - 1)
						{
							return it->start;
						}
						t.pos = it->start, t.time = target.time + pc.time;
						timepq.push(t);
						memoryInsert(pc,0);
						type = 1;
						break;
					}
				}
				if (!type)readyque.push(pc);
			}
		}
	}
}

int bestfit()
{
	int type = 0, cnt = 0;
	while (1)
	{
		process pc;
		type = 0;
		if (cnt != request.size() && (timepq.empty() || request[cnt].requestTime < timepq.top().time))
		{
			pc = request[cnt++];
			int bestsize = 1001;            
			for (it = fit[1].begin(); it != fit[1].end(); ++it)if (it->processnum == -1 && it->size >= pc.size)if (it->size < bestsize)bestsize = it->size;
			for (it = fit[1].begin(); it != fit[1].end()&&bestsize!=1001; ++it)
			{
				if (it->processnum == -1 && it->size == bestsize)
				{
					if (pc.processnum == n - 1)return it->start;
					type = 1;
					t.pos = it->start, t.time = pc.requestTime + pc.time;
					timepq.push(t);
					memoryInsert(pc,1);
					break;
				}
			}
			if (!type)readyque.push(pc);
		}
		else
		{
			int coin = 1;
			Time target;
			for (int i = 0; i < coin; i++)
			{
				target = timepq.top();
				timepq.pop();
				if (target.time == timepq.top().time)coin++;
				for (it = fit[1].begin(); it != fit[1].end(); ++it)
				{
					if (target.pos == it->start)
					{
						erase_and_merge(1);
						break;
					}
				}
			}
			int qf = readyque.size();
			for (int i = 0; i < qf; i++)
			{
				pc = readyque.front();
				readyque.pop();
				int bestsize = 1001;
				type = 0;
				for (it = fit[1].begin(); it != fit[1].end(); ++it)if (it->processnum == -1 && it->size >= pc.size)if (it->size < bestsize)bestsize = it->size;
				for (it = fit[1].begin(); it != fit[1].end() && bestsize != 1001; ++it)
				{
					if (it->processnum == -1 && it->size == bestsize)
					{
						if (pc.processnum == n - 1)return it->start;
						type = 1;
						t.pos = it->start, t.time = target.time + pc.time;
						timepq.push(t);
						memoryInsert(pc,1);
						break;
					}
				}
				if (!type)readyque.push(pc);
			}
		}
	}
	return 0;
}

int worstfit()
{
	int type = 0, cnt = 0;
	while (1)
	{
		process pc;
		type = 0;
		if (cnt != request.size() && (timepq.empty() || request[cnt].requestTime < timepq.top().time))
		{
			pc = request[cnt++];
			int worstsize = 0;
			for (it = fit[2].begin(); it != fit[2].end(); ++it)if (it->processnum == -1 && it->size >= pc.size)if (it->size > worstsize)worstsize = it->size;
			for (it = fit[2].begin(); it != fit[2].end() && worstsize != 0; ++it)
			{
				if (it->processnum == -1 && it->size == worstsize)
				{
					if (pc.processnum == n - 1)return it->start;
					type = 1;
					t.pos = it->start, t.time = pc.requestTime + pc.time;
					timepq.push(t);
					memoryInsert(pc, 2);
					break;
				}
			}
			if (!type)readyque.push(pc);
		}
		else
		{
			int coin = 1;
			Time target;
			for (int i = 0; i < coin; i++)
			{
				target = timepq.top();
				timepq.pop();
				if (target.time == timepq.top().time)coin++;
				for (it = fit[2].begin(); it != fit[2].end(); ++it)
				{
					if (target.pos == it->start)
					{
						erase_and_merge(2);
						break;
					}
				}
			}
			int qf = readyque.size();
			for (int i = 0; i < qf; i++)
			{
				pc = readyque.front();
				readyque.pop();
				int worstsize = 0;
				type = 0;
				for (it = fit[2].begin(); it != fit[2].end(); ++it)if (it->processnum == -1 && it->size >= pc.size)if (it->size > worstsize)worstsize = it->size;
				for (it = fit[2].begin(); it != fit[2].end() && worstsize != 0; ++it)
				{
					if (it->processnum == -1 && it->size == worstsize)
					{
						if (pc.processnum == n - 1)return it->start;
						type = 1;
						t.pos = it->start, t.time = target.time + pc.time;
						timepq.push(t);
						memoryInsert(pc, 2);
						break;
					}
				}
				if (!type)readyque.push(pc);
			}
		}
	}
}

int main() 
{
	freopen("allocation.inp", "r", stdin);
	freopen("allocation.out", "w", stdout);
	cin >> n;
	for (int inp = 0; inp < n; inp++)
	{
		cin >> p.requestTime >> p.time >> p.size;
		p.processnum = inp;
		request.push_back(p);
	}
	m.start = 0, m.size = 1000, m.processnum = - 1;
	fit[0].push_back(m);
	fit[1].push_back(m);
	fit[2].push_back(m); 
	cout<<firstfit()<<"\n";
	while (!timepq.empty())timepq.pop();
	while (!readyque.empty())readyque.pop();
	cout<<bestfit()<<"\n";
	while (!timepq.empty())timepq.pop();
	while (!readyque.empty())readyque.pop();
	cout << worstfit() << "\n";
}
