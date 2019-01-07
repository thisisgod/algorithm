//2048 20190107 추억의 2048 게임
#include<iostream>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)

int arr[20][20];
int arr1[20];

int main()
{
	freopen("input.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	int t, n, pt;
	char ch[6];
	cin >> t;

	f(test, t)
	{
		cout << "#" << test + 1 << "\n";
		cin >> n >> ch;
		f(inp, n) f(inp1, n) cin >> arr[inp][inp1];
		if (ch[0] == 'l')
		{
			f(i, n)
			{
				pt = 0;
				int first = -1, second = -1;
				f(j, n)
				{
					if (second <= 0 && first <= 0)
					{
						first = arr[i][j];
						if (j == n - 1)arr1[pt++] = first;
						continue;
					}
					if (second <= 0) second = arr[i][j];
					if (j == n - 1)
					{
						if (first == second)arr1[pt++] = first * 2;
						else if (first > 0)
						{
							arr1[pt++] = first;
							if (second > 0)arr1[pt++] = second;
						}
						break;
					}
					if (second == 0)continue;
					if (first == second)
					{
						arr1[pt++] = first * 2;
						first = second = -1;
					}
					else if (first != second)
					{
						arr1[pt++] = first;
						first = second;
						second = -1;
					}
				}
				f(j, n)
				{
					if (j<pt)arr[i][j] = arr1[j];
					else arr[i][j] = 0;
				}
			}
		}
		else if (ch[0] == 'r')
		{
			f(i,n)
			{
				pt = 0;
				int first = -1, second = -1;
				for (int j = n - 1; j >= 0; j--)
				{
					if (second <= 0 && first <= 0)
					{
						first = arr[i][j];
						if (j == 0)arr1[pt++] = first;
						continue;
					}
					if (second <= 0) second = arr[i][j];
					if (j == 0)
					{
						if (first == second)arr1[pt++] = first * 2;
						else if (first > 0)
						{
							arr1[pt++] = first;
							if (second > 0)arr1[pt++] = second;
						}
						break;
					}
					if (second == 0)continue;
					if (first == second)
					{
						arr1[pt++] = first * 2;
						first = second = -1;
					}
					else if (first != second)
					{
						arr1[pt++] = first;
						first = second;
						second = -1;
					}
				}
				int z = 0;
				for (int j = n - 1; j >= 0; j--)
				{
					if (z < pt)arr[i][j] = arr1[z++];
					else arr[i][j] = 0;
				}
			}
		}
		else if (ch[0] == 'u')
		{
			f(j, n)
			{
				pt = 0;
				int first=-1, second=-1;
				f(i, n)
				{
					if (second <= 0&&first<=0)
					{
						first = arr[i][j];
						if (i == n - 1)arr1[pt++] = first;
						continue;
					}
					if (second<=0) second = arr[i][j];
					if (i == n - 1)
					{
						if (first == second)arr1[pt++] = first * 2;
						else if (first > 0)
						{
							arr1[pt++] = first;
							if (second > 0)arr1[pt++] = second;
						}
						break;
					}
					if (second == 0)continue;
					if (first == second)
					{
						arr1[pt++] = first*2;
						first = second = -1;
					}
					else if (first != second)
					{
						arr1[pt++] = first;
						first = second;
						second = -1;
					}
				}
				f(i, n)
				{
					if (i<pt)arr[i][j] = arr1[i];
					else arr[i][j] = 0;
				}
			}
		}
		else
		{
			f(j,n)
			{
				pt = 0;
				int first = -1, second = -1;
				for(int i=n-1;i>=0;i--)
				{
					if (second <= 0 && first <= 0)
					{
						first = arr[i][j];
						if (i == 0)arr1[pt++] = first;
						continue;
					}
					if (second <= 0) second = arr[i][j];
					if (i == 0)
					{
						if (first == second)arr1[pt++] = first * 2;
						else if (first > 0)
						{
							arr1[pt++] = first;
							if (second > 0)arr1[pt++] = second;
						}
						break;
					}
					if (second == 0)continue;
					if (first == second)
					{
						arr1[pt++] = first * 2;
						first = second = -1;
					}
					else if (first != second)
					{
						arr1[pt++] = first;
						first = second;
						second = -1;
					}
				}
				int z = 0;
				for (int i = n - 1; i >= 0; i--)
				{
					if (z < pt)arr[i][j] = arr1[z++];
					else arr[i][j] = 0;
				}
			}
		}
		f(i, n)
		{
			f(j, n)cout << arr[i][j] << " ";
			cout << "\n";
		}
	}
}
