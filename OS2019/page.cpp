#include<iostream>
#include<vector>
#include<deque>
using namespace std;

struct process {
	int pid;
	int page;
}pro;

struct Page {
	int pid;
	int frame;
}P;

int n,a,b;
vector<process> V;
vector<process> Frame;
vector<deque<Page>> p;

void FIFO_LRU(int what)
{
	int ret = 0;
	for (int i = 0; i < V.size(); i++)
	{
		int j = 0,type=0;
		P.pid = V[i].pid;
		P.frame = Frame.size();
		for (j = 0; j < p.size(); j++)
		{
			if (V[i].pid == p[j][0].pid)
			{
				deque<Page>::iterator it;
				for (it = p[j].begin(); it != p[j].end(); it++)if (Frame[it->frame].page == V[i].page)
				{
					type = 1;
					break;
				}
				if (!what&&type == 1)break;
				if (what&&type == 1)
				{
					P = *it;
					p[j].erase(it);
					p[j].push_back(P);
					break;
				}
				if (p[j].size() == n)
				{
					P.frame = p[j][0].frame;
					Frame[P.frame].page = V[i].page;
					p[j].pop_front();
				}
				else Frame.push_back(V[i]);
				p[j].push_back(P);
				ret++;
				break;
			}
		}
		if (j == p.size())
		{
			Frame.push_back(V[i]);
			deque<Page> s;
			s.push_back(P);
			p.push_back(s);
			ret++;
		}
	}
	if (!what)
	{
		cout << "FIFO: " << ret << "\n";
		for (int i = 0; i < Frame.size(); i++)cout << i << " " << Frame[i].pid << " " << Frame[i].page << "\n";
	}
	else
	{
		cout << "LRU: " << ret << "\n";
		for (int i = 0; i < Frame.size(); i++)cout << i << " " << Frame[i].pid << " " << Frame[i].page << "\n";
	}
	Frame.clear();
	p.clear();
}

void OPT()
{
	int ret = 0;
	for (int i = 0; i < V.size(); i++)
	{
		int j = 0, type = 0;
		P.pid = V[i].pid;
		P.frame = Frame.size();
		for (j = 0; j < p.size(); j++)
		{
			if (V[i].pid == p[j][0].pid)
			{
				deque<Page>::iterator it;
				for (it = p[j].begin(); it != p[j].end(); it++)if (Frame[it->frame].page == V[i].page)
				{
					type = 1;
					break;
				}
				if (type == 1)break;
				if (p[j].size() == n)
				{
					for(int z=i;z<V.size();z++)
				}
				else Frame.push_back(V[i]);
				p[j].push_back(P);
				ret++;
				break;
			}
		}
		if (j == p.size())
		{
			Frame.push_back(V[i]);
			deque<Page> s;
			s.push_back(P);
			p.push_back(s);
			ret++;
		}
	}
	cout << "OPT: " << ret << "\n";
	for (int i = 0; i < Frame.size(); i++)cout << i << " " << Frame[i].pid << " " << Frame[i].page << "\n";
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	cin >> n;
	cin >> a >> b;
	while (a != -1)
	{
		pro.pid = a;
		pro.page = b;
		V.push_back(pro);
		cin >> a >> b;
	}
	for(int i=0;i<2;i++)FIFO_LRU(i);
}
