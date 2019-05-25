#include<iostream>
#include<stdio.h>
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
vector< deque<Page> > p;

void FIFO_LRU_OPT(int what)
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
				if ((!what||what==2)&&type == 1)break;
				if (what&&type == 1)
				{
					P = *it;
					p[j].erase(it);
					p[j].push_back(P);
					break;
				}
				if (p[j].size() == n)
				{
					if (what < 2)
					{
						P.frame = p[j][0].frame;
						Frame[P.frame].page = V[i].page;
						p[j].pop_front();
					}
					else if (what == 2)
					{
						deque<Page> s = p[j];
						for (int z = i; z < V.size() && s.size() != 1; z++)for (it = s.begin(); it != s.end(); it++)if (it->pid == V[z].pid&&Frame[it->frame].page == V[z].page)
						{
							s.erase(it);
							break;
						}
						if (s.size() == 1)
						{
							P.frame = s[0].frame;
							Frame[s[0].frame].page = V[i].page;
							for (it = p[j].begin(); it != p[j].end(); it++)if (it->frame == s[0].frame)break;
							p[j].erase(it);
						}
						else if (s.size() > 1)
						{
							for (int z = 0; z < p[j].size() && !type; z++)for (int k = 0; k < s.size(); k++)if (p[j][z].frame == s[k].frame)
							{
								P.frame = s[k].frame;
								Frame[s[k].frame].page = V[i].page;
								for (it = p[j].begin(); it != p[j].end(); it++)if (it->frame == s[k].frame)break;
								p[j].erase(it);
								type = 1;
								break;
							}
						}
					}
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
	else if(what==1)
	{
		cout << "LRU: " << ret << "\n";
		for (int i = 0; i < Frame.size(); i++)cout << i << " " << Frame[i].pid << " " << Frame[i].page << "\n";
	}
	else if (what == 2)
	{
		cout << "OPT: " << ret << "\n";
		for (int i = 0; i < Frame.size(); i++)cout << i << " " << Frame[i].pid << " " << Frame[i].page << "\n";
	}
	Frame.clear();
	p.clear();
}

int main()
{
	freopen("page.inp", "r", stdin);
	freopen("page.out", "w", stdout);

	cin >> n;
	cin >> a >> b;
	while (a != -1)
	{
		pro.pid = a;
		pro.page = b;
		V.push_back(pro);
		cin >> a >> b;
	}
	for(int i=0;i<3;i++)FIFO_LRU_OPT(i);
}
