//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define dbg(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string vars, Args &&...values)
{
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ","));
    cout << endl;
}

#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

int n;
class TrieNode
{
public:
    int freq;
    vector<TrieNode *> child;
    TrieNode()
    {
        freq = 0;
        child = vector<TrieNode *>(256, NULL);
    }
};
void insert(TrieNode *root, string s)
{
    TrieNode *cur = root;
    for (auto x : s)
    {
        int ind = x;
        if (cur->child[ind] == NULL)
        {
            TrieNode *node = new TrieNode();
            cur->child[ind] = node;
        }
        cur = cur->child[ind];
        cur->freq++;
    }
}
void uniquePrefix(TrieNode *root, vector<string> &ans, string pref)
{
    //https://www.geeksforgeeks.org/find-all-shortest-unique-prefixes-to-represent-each-word-in-a-given-list/
    if(root==NULL)
        return;

    if (root->freq == 1)
    {
        ans.push_back(pref);
        return;
    }
    for (int i = 0; i < 256; i++)
    {
        if (root->child[i] != NULL)
        {
            char ch = i;
            uniquePrefix(root->child[i], ans, (pref+ch));
        }
    }
}
void solve()
{
    int i, j, k;
    vector<string> a = {"zebra", "dog", "duck", "dove"};
    TrieNode *root = new TrieNode();

    for (auto s : a)
    {
        insert(root, s);
    }

    vector<string> uniquePrefixAns;
    string pref = "";

    uniquePrefix(root, uniquePrefixAns, pref);
    for (auto s : uniquePrefixAns)
    {
        cout << s << endl;
    }

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
//#ifndef ONLINE_JUDGE
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif