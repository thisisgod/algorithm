#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int n;
struct process {
	int number, arrive, burst;
};

process pro[50];

bool compare(const process &a, const process &b)
{
	if (a.arrive == b.arrive)return a.number < b.number;
	return a.arrive < b.arrive;
}

int main()
{
	freopen("fcfs.inp", "r", stdin);
	freopen("fcfs.out", "w", stdout);
	cin >> n;
	for (int inp = 0; inp < n; inp++)cin >> pro[inp].number >> pro[inp].arrive >> pro[inp].burst;
	sort(pro, pro + n, compare);
	int cnt = 0, totalburst = pro[0].burst;
	for (int i = 1; i < n; i++)
	{
		if (totalburst < pro[i].arrive)totalburst = pro[i].arrive;
		cnt += totalburst - pro[i].arrive;
		totalburst += pro[i].burst;
	}
	cout << cnt;
}
