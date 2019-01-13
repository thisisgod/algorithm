//유레카 이론 20190111 
#include<iostream>
using namespace std;
#define f(i,k,n) for(int i=k;i<n;i++)

int T[46];

int main()
{
	freopen("inp.inp", "r", stdin);
	freopen("out.out", "w", stdout);

	int t, k, result;
	cin >> t;

	f(i,1, 45) T[i] = T[i - 1] + i;
	f(test, 0, t)
	{
		cin >> k;
		result = 0;
		f(i, 1, 45)
		{
			if (T[i] > k)break;
			f(j, 1, 45)
			{
				if (T[i] + T[j] > k)break;
				f(z, 1, 45)
				{
					if (T[i] + T[j] + T[z] > k)break;
					if (T[i] + T[j] + T[z] == k)result = 1;
				}
			}
		}
		cout << result << "\n";
	}
}
