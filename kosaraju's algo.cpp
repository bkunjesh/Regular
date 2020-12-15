#include<bits/stdc++.h>
using namespace std;
vector<int> g[100000], R[100000];
int visited[100000];
void dfs(int node, stack<int> &s)
{
	visited[node] = 1;
	for (auto child : g[node])
	{
		if (!visited[child])
			dfs(child, s);
	}
	s.push(node);
}
void reverse(int n)
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (auto child : g[i])
			R[child].push_back(i);//, cout << child << " " << i << endl;

	}
}

int main()
{
	/*input
	5 5
	3 4
	1 0
	2 1
	0 2
	0 3*/
	int i, j, k, n, e; cin >> n >> e;
	memset(visited, 0, sizeof(visited[100000]));
	for (i = 0; i < e; i++) cin >> j >> k, g[j].push_back(k);

	stack<int> s;
	for (i = 0; i < n; i++)
		if (!visited[i]) dfs(i, s);
	reverse(n);
	memset(visited, 0, sizeof(visited));
	while (!s.empty())
	{
		//for (i = 0; i < 5; i++) cout << visited[i] << " ";
		//cout << endl;
		queue<int> q;
		int top = s.top();
		s.pop();

		if (!visited[top]) q.push(top), cout << top << " ";
		else continue;
		while (!q.empty())
		{
			int front = q.front();
			visited[front] = 1;
			q.pop();
			for (auto child : R[front])
				if (!visited[child])
				{
					q.push(child);
					cout << child << " ";
				}

		}
		cout << endl;
	}
}

