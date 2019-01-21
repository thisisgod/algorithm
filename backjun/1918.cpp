//후위표기식 20190121 스택
#include<iostream>
#include<stack>
#include<string>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

string str;
stack<char> st;

int check(char ch)
{
	if (ch == '+' || ch == '-')return 1;
	if (ch == '*' || ch == '/')return 2;
	return 3;
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	getline(cin, str);
	f(i, 0, str.length())
	{
		if (str[i] <= 'Z'&&str[i] >= 'A')cout << str[i];
		else if (str[i] == ')')
		{
			for (; !st.empty();)
			{
				if (st.top() == '(')
				{
					st.pop();
					break;
				}
				cout << st.top();
				st.pop();
			}
		}
		else
		{
			if (st.empty() ||st.top()=='('|| check(st.top()) < check(str[i]))st.push(str[i]);
			else
			{
				for (; !st.empty();)
				{
					if (st.top() == '(') break; 
					if (check(st.top()) < check(str[i]))break;
					cout << st.top();
					st.pop();
				}
				st.push(str[i]);
			}
		}
	}
	for (; !st.empty();)
	{
		if (st.top() != '(') cout << st.top();
		st.pop();
	}
}
