//외계인의 기타 연주 20190212 스택
#include<iostream>
#include<stack>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

int n,p,cnt;
stack <int> st[7];

void solve(int line, int plet)
{
	if (st[line].empty() || st[line].top() <plet)
	{
		st[line].push(plet);
		cnt++;
		return;
	}
	while (!st[line].empty()&&st[line].top() >= plet)
	{
		if (st[line].top() == plet)return;
		else st[line].pop();
		cnt++;
	}
	st[line].push(plet);
	cnt++;
}

int main()
{
	cin >> n >> p;
	int line, plet;
	f(i, 0, n)
	{
		cin >> line >> plet;
		solve(line, plet);
	}
	cout << cnt;
}
