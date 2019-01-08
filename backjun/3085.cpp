//사탕게임 20190108 3085
#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define f(i,x,n) for(int i=x;i<n;i++)

string str;
vector <string> vec;

int dx[2] = { 1,0 };
int dy[2] = { 0,1 };
int n;
char tmp;
int result;

void resultsearch()
{
	int cnt;
	f(i, 0, n)
	{
		tmp = vec[i][0];
		cnt = 1;
		f(j, 1, n)
		{
			if (vec[i][j] == tmp)cnt++;
			else if (vec[i][j] != tmp)
			{
				result = result > cnt ? result : cnt;
				tmp = vec[i][j];
				cnt = 1;
			}
		}
		result = result > cnt ? result : cnt;
	}
	f(j, 0, n)
	{
		tmp = vec[0][j];
		cnt = 1;
		f(i, 1, n)
		{
			if (vec[i][j] == tmp)cnt++;
			else if (vec[i][j] != tmp)
			{
				result = result > cnt ? result : cnt;
				tmp = vec[i][j];
				cnt = 1;
			}
		}
		result = result > cnt ? result : cnt;
	}
}

void candy(int x, int y)
{
	f(i, y, n)
	{
		f(j, x, n)
		{
			f(z, 0, 2)
			{
				if (i + dy[z] >= 0 && i + dy[z] < n&&j + dx[z] >= 0 && j + dx[z] < n)
				{
					tmp = vec[i][j];
					vec[i][j] = vec[i + dy[z]][j + dx[z]];
					vec[i + dy[z]][j + dx[z]] = tmp;
					resultsearch();
					tmp = vec[i][j];
					vec[i][j] = vec[i + dy[z]][j + dx[z]];
					vec[i + dy[z]][j + dx[z]] = tmp;
				}
			}
		}
	}
}

int main()
{
	freopen("input.inp", "r", stdin);
	freopen("out.out", "w", stdout);
	
	cin >> n;
	getchar();

	f(i,0, n)
	{
		getline(cin, str);
		vec.push_back(str);
	}
	resultsearch();
	candy(0,0);
	cout << result;

}
