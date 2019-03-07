//[S/W 문제해결 응용] 1일차 - 단순 2진 암호코드 20190307
#include<iostream>
using namespace std;

int n, m;
int code1[10] =
{
	88,76,100,94,98,70,122,110,118,104
};
char map[50][100];

int solve(int i, int j)
{
	int first, last, arr[8];
	int a, cnt;
	first = j;
	for (int z = j; z < j + 56 && z < m; z++)
	{
		if (map[i][z] == '1')last = z;
	}
	cnt = 0;
	for (int k = last - 55; k <= last; k += 7)
	{
		a = 0;
		for (int q = 0, sec = 1; q < 7; q++, sec *= 2)
		{
			a += (map[i][k + q] - '0')*sec;
		}
		for (int q = 0; q < 10; q++)
		{
			if (a == code1[q])arr[cnt++] = q;
		}
	}
	if (cnt == 8)
	{
		if (((arr[0] + arr[2] + arr[4] + arr[6]) * 3 + arr[1] + arr[3] + arr[5] + arr[7]) % 10 == 0)
		{
			int result = 0;
			for (int i = 0; i < 8; i++)result += arr[i];
			return result;
		}
	}
	return 0;
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	int t,type;
	cin >> t;
	for (int test = 0; test < t; test++)
	{
		cout << '#' << test + 1 << " ";
		cin >> n >> m;
		for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)map[i][j] = 0;
		type = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> map[i][j];
				if(map[i][j]=='1'&&type==0)type = j;
			}
			if (type>0)
			{
				cout << solve(i, type)<<"\n";
				type = -1;
			}
		}
	}
}
