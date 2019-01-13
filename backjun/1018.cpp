//체스판 다시 칠하기 20190111 
//체스판 왼쪽위에 올수 있는 색깔의 경우는 2가지(흰,검)
//8*8의 절반은 32 따라서 ret이 32가넘으면 색을 바꿔서 칠하는게 더 이득이다.
#include<iostream>
#include<algorithm>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

char map[51][51];
char paint[2] = { 'W','B' };

int check(int h, int w)
{
	int cnt = 0;
	int ret = 0;
	f(i, h - 7, h + 1)
	{
		f(j, w - 7, w + 1)
		{
			if (paint[cnt % 2] != map[i][j])ret++;
			cnt++;
		}
		cnt++;
	}
	return ret>32?64-ret:ret;
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	int result,M,N;
	
	cin >> N >> M;

	f(i, 0, N)
	{
		f(j, 0, M)
		{
			cin >> map[i][j];
		}
	}
	result = 987654321;
	f(i, 7, N)
	{
		f(j, 7, M)
		{
			result = min(result, check(i, j));
		}
	}
	cout << result;
}
