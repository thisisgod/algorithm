#include<iostream>
#include<math.h>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define Ms 20000

int rev(int a) { return a % 2 ? a - 1 : a + 1; }

struct _2SAT{
	int scc[Ms], low[Ms], order[Ms], cnt, c, result[Ms/2];
	bool visit[Ms];
	stack<int> s;
	vector<int>adj[Ms];

	void dfs(int now) {
		visit[now] = true;
		s.push(now);
		order[now] = low[now] = ++c;
		for (int next : adj[now]) {
			if (visit[next]) {
				low[now] = min(low[now], order[next]);
				continue;
			}
			else if (!order[next]) {
				dfs(next);
				low[now] = min(low[now], low[next]);
			}
		}
		if (low[now] == order[now]) {
			++cnt;
			while (!s.empty()) {
				int tmp = s.top();
				s.pop();
				scc[tmp] = cnt;
				visit[tmp] = false;
				if (tmp == now)return;
			}
		}
	}

	void makeScc(int n) { for (int i = 0; i < n * 2; i++)if (!order[i])dfs(i); }

	int solve(int n) {// 가능성 판단
		for (int i = 0; i < n * 2; i += 2)if (scc[i] == scc[i + 1])return 0;
		return 1;
	}

	void solve1(int n) { // 어떤걸로 가능한지 탐색
		for (int i = 0; i < n; i++)result[i] = -1;

		P p[Ms];
		for (int i = 0; i < n * 2; i++)p[i] = { scc[i],i };
		sort(p, p + n * 2);

		for (int i = n * 2 - 1; i >= 0; i--) {
			int var = p[i].second;
			if (result[var / 2] == -1)result[var / 2] = !(var % 2);
		}
		for (int i = 0; i < n; i++)cout << result[i] << ' ';
	}

	void inp(int n,int m) {
		int a, b;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			a = a < 0 ? -(a + 1) * 2 : a * 2 - 1;
			b = b < 0 ? -(b + 1) * 2 : b * 2 - 1;
			adj[rev(a)].push_back(b);
			adj[rev(b)].push_back(a);
		}
	}
};

_2SAT s;
int n, m;

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	s.inp(n, m);
	s.makeScc(n);
	if (s.solve(n)) cout << "^_^";
	else cout << "OTL";
}
