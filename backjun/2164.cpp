//카드2 20190119 큐
#include<iostream>
#include<queue>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

int n;

int main()
{
	queue<int> que;
	cin >> n;

	f(i, 1, n+1) que.push(i);
	f(i, 1, n)
	{
		que.pop();
		que.push(que.front());
		que.pop();
	}
	cout << que.front();
}
