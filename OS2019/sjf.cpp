#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define INF 999999

int n, hcnt = 1;

struct process {
	int number=INF, arrive=INF, burst=INF;
};

process heap[51];
process pro[50];

bool compare(const process &a, const process &b)
{
	if (a.arrive == b.arrive)return a.number < b.number;
	return a.arrive < b.arrive;
}

int swap1(int f, int s)
{
	process tmp = heap[f];
	heap[f] = heap[s];
	heap[s] = tmp;
	return s;
}

void push(process inp)
{
	if (hcnt == 1)heap[hcnt++] = inp;
	else
	{
		heap[hcnt] = inp;
		for (int i = hcnt++; i > 1; i /= 2)
		{
			if (heap[i].burst == heap[i / 2].burst)
			{
				if (heap[i].arrive == heap[i / 2].arrive)
				{
					if (heap[i].number < heap[i / 2].number)swap1(i, i / 2);
				}
				else if (heap[i].arrive < heap[i / 2].arrive)swap1(i, i / 2);
			}
			if (heap[i].burst < heap[i / 2].burst) swap1(i, i / 2);
			else break;
		}
	}
}

process pop()
{
	process ret = heap[1];
	hcnt--;
	heap[1] = heap[hcnt];
	heap[hcnt].burst = heap[hcnt].arrive=heap[hcnt].number=INF;
	for (int i = 1; i < hcnt;)
	{
		if (i * 2 > 49)break;
		if (heap[i].burst == heap[i * 2].burst)
		{
			if (heap[i].arrive == heap[i * 2].arrive)
			{
				if (heap[i].number > heap[i * 2].number)swap1(i, i * 2);
			}
			else if (heap[i].arrive > heap[i * 2].arrive)swap1(i, i * 2);
		}
		else if (heap[i].burst == heap[i * 2 + 1].burst)
		{
			if (heap[i].arrive == heap[i * 2 + 1].arrive)
			{
				if (heap[i].number > heap[i * 2 + 1].number)swap1(i, i * 2 + 1);
			}
			else if (heap[i].arrive > heap[i * 2 + 1].arrive)swap1(i, i * 2 + 1);
		}
		if (heap[i].burst < heap[i * 2].burst&&heap[i].burst < heap[i * 2 + 1].burst) break;
		i = heap[i * 2].burst > heap[i * 2 + 1].burst ? swap1(i, i * 2 + 1) : swap1(i, i * 2);
	}
	return ret;
}

bool empty()
{
	return hcnt == 1;
}

int main()
{
	freopen("3.inp", "r", stdin);
	freopen("out.out", "w", stdout);
	cin >> n;
	int a, b, c,i;
	for (int inp = 0; inp < n; inp++)
	{
		cin >> a >> b >> c;
		pro[inp].number = a;
		pro[inp].arrive = b;
		pro[inp].burst = c;
	}
	sort(pro, pro + n, compare);
	int cnt = 0, totalburst = pro[0].burst;
	for (i = 1; pro[i].arrive <= totalburst; i++)
	{
		push(pro[i]);
		pro[i].arrive = pro[i].burst = pro[i].number = INF;
	}
	for (i; i < n;)
	{
		if (empty()) totalburst = pro[i].arrive;
		else
		{
			process tmp = pop();
			cnt += totalburst - tmp.arrive;
			totalburst += tmp.burst;
		}
		for (i; pro[i].arrive <= totalburst; i++)
		{
			push(pro[i]);
			pro[i].arrive = pro[i].burst = pro[i].number = INF;
		}
	}
	for (; !empty();)
	{
		process tmp = pop();
		cnt += totalburst - tmp.arrive;
		totalburst += tmp.burst;
	}
	cout << cnt;
}
