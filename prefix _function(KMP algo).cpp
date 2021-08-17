//@ikung
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0);
#define f(i, k) for (int i = 0; i < k; i++)
#define F first
#define dbg(x) cout << #x << " " << x << endl;
#define S second
#define endl "\n"
#define rep(i, n) for (int i = 1; i <= n; i++)
#define rew(i, a, b) for (int i = a; i <= b; i++)
#define mod 1000000007
const int inf = 1e18;
const int N = 200005;

// pi[i]  is the length of the longest prefix of the substring s[0…i] which is
// also a suffix of this substring

// string s= fixprefixsuffix
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14    index
// f i x p r e f i x s  u  f  f  i  x
// 0 0 0 0 0 0 1 2 3 0  0  1  1  2  3    pi

// string s= aabcaacdaabcaa
// a a b c a a c d a a b c a a
// 0 1 0 0 1 2 0 0 1 2 3 4 5 6

vector<int> prefix_function(string s)
{

    // https://cp-algorithms.com/string/prefix-function.html
    
    int n = s.size(), i, j;
    vector<int> pi(n + 1);

    for (i = 1; i < n; i++)
    {
        j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
        cout << pi[i] << " ";
    }

    return pi;
}

void solve()
{
    int i, j, k, n;

    string s;
    cin >> s;
    // s = "hhihh";
    auto pi = prefix_function(s);
    n = s.size();
    if (pi[n - 1] == 0)
    {
        cout << "Just a legend" << endl;
        return;
    }
    else
    {
        f(i, n - 1)
        {
            if (pi[i] == pi[n - 1])
            {
                cout << s.substr(0, pi[n - 1]) << endl;
                return;
            }
        }

        if (pi[pi[n - 1] - 1] == 0)
        {
            cout << "Just a legend" << endl;
            return;
        }
        else
        {
            cout << s.substr(0, pi[pi[n - 1] - 1]) << endl;
            return;
        }
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
