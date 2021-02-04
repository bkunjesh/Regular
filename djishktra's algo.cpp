//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define mod 1000000007
const int inf = 1e18;
const int N = 1000005;

int n;
vector<pair<int, int>> g[N];
vector<int> dist(N, inf), visited(N);
void solve()
{
	int i, j, k;

	int m, a, b, c;
	cin >> n >> m;
	f(i, m) cin >> a >> b >> c, g[a].push_back({b, c});

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //(dist,node)
	dist[1] = 0;
	pq.push({0, 1});

	while (!pq.empty())
	{
		auto p = pq.top();
		pq.pop();

		int node = p.S;
		int d = p.F;

		visited[node] = 1;

		if (dist[node] < d) continue; //imp line ...it may cause tle if not wrriten

		for (auto child : g[node])
		{
			if (!visited[child.F])
			{
				if (dist[child.F] < d + child.S) continue;  //imp line ...it may cause tle if not wrriten

				dist[child.F] = min(dist[child.F], d + child.S);
				pq.push({dist[child.F], child.F});
			}
		}
	}
	rep(i, n) cout << dist[i] << " ";

	return;
}

signed main()
{
	fast int t = 1, i, j, k;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}