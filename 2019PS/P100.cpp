#include<iostream>
#include<algorithm>
using namespace std;

int cycle(int cur)
{
	int ret = 1;
	for (; cur != 1;ret++) cur = (cur % 2 == 0) ? cur >> 1 : cur * 3 + 1;
	return ret;
}

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);
	int fir, sec, ret,a,b;
	while (cin >> fir >> sec)
	{
		a = fir > sec?sec:fir;
		b = fir > sec ? fir : sec;
		ret = 0;
		for (int i = a; i <= b; i++)ret = max(ret, cycle(i));
		cout << fir << " " << sec << " " << ret << "\n";
	}
}       
