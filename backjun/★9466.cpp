//텀 프로젝트 20190212 dps(사이클 찾기) 더 잘 풀수 있을거같으니 다시풀어볼것
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

int n,cnt;
int check[100001];
bool visit[100001];
stack<int>st;

void solve(int current, int first, vector<int>&v)
{
	visit[current] = true;
	st.push(first);
	for (;;)
	{
		check[current] = first;
		if (!visit[v[current]])
		{
			st.push(current);
			current = v[current];
			visit[current] = true;
		}
		else if (v[current] == first)
		{
			check[current] = -1;
			while (!st.empty())
			{
				check[st.top()] = -1;
				st.pop();
			}
			return;
		}
		else if (check[v[current]]==first)
		{
			check[current] = -1;
			while (!st.empty()&&st.top() != v[current])
			{
				check[st.top()] = -1;
				st.pop();
			}
			check[st.top()] = -1;
			while (!st.empty())st.pop();
			return;
		}
		else
		{
			while (!st.empty())st.pop();
			return;
		}
	}
}


int main()
{

	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	int t;
	cin >> t;

	f(test, 0, t)
	{
		cin >> n;

		vector<int> v;
		cnt = 0;
		v.push_back(0);
		int tmp;

		f(inp, 1, n + 1)
		{
			cin >> tmp;
			v.push_back(tmp);
			if (inp == tmp)
			{
				check[inp] = -1;
				visit[inp] = true;
			}
			else
			{
				check[inp] = false;
				visit[inp] = false;
			}
		}
		
		f(i, 1, n + 1)
		{
			if (!visit[v[i]])
			{
				visit[i] = true;
				solve(v[i], i, v);
			}
		}
		f(i, 1, n + 1)if (check[i]!=-1)cnt++;
		cout << cnt<<"\n";
	}
}
