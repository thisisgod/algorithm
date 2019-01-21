//AC 20190121 
#include<iostream>
#include<queue>
#include<string>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

int t,n,num;
int arr[100000];
int head;
int back;
bool state;
string str;

bool empty()
{
	return state ? head == back - 1 : back == head - 1;
}

void pop()
{
	if (empty()) return;
	if(state) head--;
	else head++;
}

void push(int a)
{
	arr[back++] = a;
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	cin >> t;
	f(test, 0, t)
	{
		state = false;
		head = 0;
		back = 0;
		getchar();
		getline(cin, str);
		cin >> n;
		getchar();
		f(inp, 0, n)
		{
			getchar();
			cin >> num;
			push(num);
		}
		if(n==0)getchar();
		getchar();
		back--;
		f(i, 0, str.length())
		{
			if (str[i] == 'D')
			{
				if (!empty())pop();
				else
				{
					cout << "error\n";
					break;
				}
			}
			else if (str[i] == 'R')
			{
				int tmp = head;
				head = back;
				back = tmp;
				state = !state;
			}
			if (i == str.length() - 1)
			{
				cout << "[";
				for (;!empty();)
				{
					cout << arr[head];
					if (head == back) break;
					else cout << ",";
					pop();
				}
				cout << "]\n";
			}
		}
	}
}
