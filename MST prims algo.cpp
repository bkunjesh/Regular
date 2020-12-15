#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int>> g[100000];
int visited[100000];

int main()
{
	int i, j, k, n, e, w; cin >> n >> e;
	for (i = 0; i < e; i++) cin >> j >> k >> w, g[j].push_back({k, w}), g[k].push_back({j, w});
	int dist[n + 1], parent[n + 1];
	memset(visited, 0, sizeof(visited));
	for (i = 0; i < n; i++) dist[i] = INT_MAX;
	dist[0] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //   (dist,node)
	q.push({0, 0});
	while (!q.empty())
	{
		pair<int, int> p = q.top();
		q.pop();
		int node = p.second, d = p.first;

		visited[node] = 1;

		for (auto child : g[node])
			if (!visited[child.first])
			{
				if (child.second < dist[child.first])
				{
					dist[child.first] = child.second;
					parent[child.first] = node;
				}
				q.push({dist[child.first], child.first});
			}
	}

	for (i = 0; i < n; i++) cout << parent[i] << " " << i << endl;

}
/*9 14
	0 1 4
	0 7 8
	1 7 11
	1 2 8
	7 8 7
	7 6 1
	2 8 2
	2 5 4
	8 6 6
	6 5 2
	2 3 7
	3 5 14
	3 4 9
	5 4 10*/

