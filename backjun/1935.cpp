//후위표기법2 20190121 스택
#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

string str;
stack<double> sti;
int arr[26];
int n;

void circul(char ch)
{
	double a, b;
	a = sti.top();
	sti.pop();
	b = sti.top();
	sti.pop();
	if (ch == '+')sti.push(a + b);
	else if (ch == '-')sti.push(b - a);
	else if (ch == '/')sti.push(b / a);
	else if (ch == '*')sti.push(a*b);
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);
	cin >> n;
	getchar();
	getline(cin, str);
	f(i, 0, n)cin >> arr[i];
	f(i, 0, str.length())
	{
		if (str[i] <= 'Z'&&str[i] >= 'A')
		{
			sti.push(arr[str[i] - 'A']);
		}
		else circul(str[i]);
	}
	printf("%.2lf", sti.top());
}
