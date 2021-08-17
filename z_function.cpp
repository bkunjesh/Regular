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
const int N = 200005;



//An element Z[i] of Z array stores length of the longest substring starting from str[i] which is also a prefix of str[0..n-1].

vector<int> z_function(string s)
{

    // https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/
    // https://cp-algorithms.com/string/z-function.html

    int n = s.size(), l=0, r=0, i;
    vector<int> z(n);
    for (i = 1; i < n;i++)
    {
        if(i>r)
        {
            l = i, r = i;
            while(r<n&&s[r-l]==s[r])
                r++;
            z[i] = r - l;
            r--;
        }
        else
        {
            int k=i-l;
            
            if(z[k]<r-i+1)
            {
                z[i] = z[k];
            }
            else
            {
                l = i;
                while (r < n && s[r - l] == s[r])
                    r++;
                z[i] = r - l;
                r--;
            }
        }
        // cout << z[i] << " ";
    }

    return z;
}


vector<int> prefix_function(string s)
{
    int n = s.size(), i, j;
    vector<int> pi(n);
    for (i = 1; i < n; i++)
    {
        j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
        // cout << pi[i] << " ";
    }
    return pi;
}


void solve()
{
    int i, j, k, n, m;
    string s, p;
    cin >> s >> p;
    n = s.size();
    m = p.size();
    string t = p + '#' + s;
    // cout << t << endl;
    

    // // 1. prefix_function  (KMP algo)
    // auto fun = prefix_function(t);
    
    // 2. z_function
    auto fun = z_function(t);
    

    int pattern_occurence = 0;
    for (i = 0;i<fun.size();i++)
        if (fun[i] == m)
            pattern_occurence++,i+=m-1;

    cout << pattern_occurence << endl;

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