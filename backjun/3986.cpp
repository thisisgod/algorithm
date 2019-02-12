//좋은 단어 20190212 스택
#include<iostream>
#include<stack>
#include<string>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

int n,cnt;
string str;

void solve(stack<char> &st)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (st.empty() || st.top() != str[i])st.push(str[i]);
		else st.pop();
	}
	if (st.empty())cnt++;
}

int main()
{
	cin >> n;
	getchar();
	f(i, 0, n)
	{
		getline(cin, str);
		stack <char> st;
		solve(st);
	}
	cout << cnt;
}
