//@CodesUp
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define mod 1000000007
const int inf = 1e18;
const int N = 100005;
vector<int> visited(100005), level(100005), val(100005);
//vector<pair<int, int>> g[100005];
vector<int> g[100005];
int MAXN=log2(N);
int lca[100005][25];

// void make_edge(int a, int b, int w)
// {
//     g[a].push_back({b, w}), g[b].push_back({a, w});
// }

void make_edge(int a, int b)
{
    g[a].push_back(b), g[b].push_back(a);
}

void dfs(int node, int parent, int d)
{
    lca[node][0] = parent;
    level[node] = d;
    visited[node] = 1;

    for (auto child : g[node])
    {
        if (!visited[child])
        {
            
            dfs(child, node, d + 1);
        }
    }
}

void buildlca(int n)
{
    for (int j = 1; j <= MAXN; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (lca[i][j - 1] != -1)
            {
                lca[i][j] = lca[lca[i][j - 1]][j - 1];
            }
        }
    }
}
int getlca(int a, int b)
{
    if (level[a] > level[b])
    {
        swap(a, b);
    }
    int d = level[b] - level[a];

    while (d > 0)
    {
        int i = log2(d);
        b = lca[b][i];
        d -= (1 << i);
    }
    if (a == b)
        return a;
    for (int i = MAXN; i >= 0; i--)
    {
        if (lca[a][i] != -1 && lca[a][i] != lca[b][i])
        {
            a = lca[a][i], b = lca[b][i];
        }
    }
    return lca[a][0];
}