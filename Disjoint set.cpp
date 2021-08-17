//@ikung
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define f(i,k) for(int i=0;i<k;i++)
#define F first
#define dbg(x)  cout<<#x<<" "<<x<<endl;
#define S second
#define endl "\n"
#define rep(i,n) for(int i=1;i<=n;i++)
#define rew(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
const int inf = 1e18;
// const int N=200005;

int n;

struct DisjointSet 
{
    int *rank, *parent;
    DisjointSet(int N)
    {
        rank=new int[N+1];
        parent=new int[N+1];
        for(int i=0;i<=N;i++)
        {
            rank[i]=1;
            parent[i]=i;
        }
    }
    
    int find(int x){
       if(parent[x]!=x){
           parent[x]=find(parent[x]);
       }
        return parent[x];
    }
    
    void union_rank(int a,int b){
        int pa=find(a);
        int pb=find(b);
        if(pa==pb)
        return;
        if(rank[pa] > rank[pb])
        {
            parent[pb]=pa;
            rank[pa]+=rank[pb];
        }
        else {
            parent[pa]=pb;
            rank[pb]+=rank[pa];
        }
    }
    
};


void solve()
{
    int i, j, k;
    
    int m;
    cin>>n>>m;
    DisjointSet d(1000000);
    while(m--)
    {
        int par;
        cin>>j;
        if(j) cin>>par;
        j--;
        if(j>0)
        while(j--)
        {
            cin>>k;
            d.union_rank(par,k);
        }
    }
    map<int,int> mp;
    rep(i,n) mp[d.find(i)]++;

    rep(i,n)
    {
        cout<<mp[d.find(i)]<<" ";
    }
    cout<<endl;

// https://codeforces.com/problemset/problem/1167/C
    return;
}

signed main()
{
    fast
    int t = 1, i, j, k;
    //cin >> t;
    while (t--)
    {
        solve();		
    }
return 0;
}