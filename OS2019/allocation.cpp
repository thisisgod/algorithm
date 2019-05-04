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

int firstcycle(process pc)
{
	int type = 0;
	for (it = fit[0].begin(); it != fit[0].end(); ++it)
	{
		if (it->processnum == -1 && it->size >= pc.size)
		{
			if (pc.processnum == n - 1)return it->start;
			t.pos = it->start, t.time = pc.requestTime + pc.time;
			timepq.push(t);
			memoryInsert(pc, 0);
			type = 1;
			break;
		}
	}
	if (!type)readyque.push(pc);
	return -1;
}

int bestcycle(process pc)
{
	int bestsize = 1001,type=0;
	for (it = fit[1].begin(); it != fit[1].end(); ++it)if (it->processnum == -1 && it->size >= pc.size)if (it->size < bestsize)bestsize = it->size;
	for (it = fit[1].begin(); it != fit[1].end() && bestsize != 1001; ++it)
	{
		if (it->processnum == -1 && it->size == bestsize)
		{
			if (pc.processnum == n - 1)return it->start;
			type = 1;
			t.pos = it->start, t.time = pc.requestTime + pc.time;
			timepq.push(t);
			memoryInsert(pc, 1);
			break;
		}
	}
	if (!type)readyque.push(pc);
	return -1;
}

int worstcycle(process pc)
{
	int worstsize = 0,type=0;
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
	return -1;
}

int selectcycle(int what,process pc)
{
	if (what == 2)return worstcycle(pc);
	else if (what == 1)return bestcycle(pc);
	else return firstcycle(pc);
}

int selectfit(int what)
{
	int type = 0, cnt = 0, ret = -1;
	while (!timepq.empty())timepq.pop();
	while (!readyque.empty())readyque.pop();
	while (1)
	{
		process pc;
		type = 0;
		if (cnt != request.size() && (timepq.empty() || request[cnt].requestTime < timepq.top().time))
		{
			pc = request[cnt++];
			ret=selectcycle(what,pc);
			if (ret!=-1)return ret;
		}
		else
		{
			int coin = 1;
			Time target;
			for (int i = 0; i < coin; i++)
			{
				target = timepq.top();
				timepq.pop();
				if (!timepq.empty()&&target.time == timepq.top().time)coin++;
				for (it = fit[what].begin(); it != fit[what].end(); ++it)
				{
					if (target.pos == it->start)
					{
						erase_and_merge(what);
						break;
					}
				}
			}
			int qf = readyque.size();
			for (int i = 0; i < qf; i++)
			{
				pc = readyque.front();
				readyque.pop();
				pc.requestTime = target.time;
				ret = selectcycle(what,pc);
				if (ret!=-1)return ret;
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
	for(int i=0;i<3;i++)fit[i].push_back(m);
	for(int i=0;i<3;i++)cout<<selectfit(i)<<"\n";
}
