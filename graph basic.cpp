#include<bits/stdc++.h>
using namespace std;
#define ll long long


class Graph
{
    private:
    vector<vector<ll>> g;
    vector<ll> visited,in,out,Flattree;
    ll n,timer;
    public:
    vector<ll> nodeweight;
    Graph(ll n)
    {
        this->n=n;
        visited.assign(n+1,0);
        g.resize(n+1);
        in.assign(n+1,0);
        out.assign(n+1,0);
        Flattree.assign(2*n+2,0);
        nodeweight.assign(n+1,0);
        this->timer=1;
        
    }
    void make_edge(ll a,ll b)
    {
        g[a].push_back(b),g[b].push_back(a);
    }
    void dfs(ll node,ll parent)
    {
        visited[node]=1;
        in[node]=timer;
        Flattree[timer++]=node;

        for(auto child:g[node])
        {
            if(!visited[child])
            {
                dfs(child,parent);
            }
        }

        out[node]=timer;
        Flattree[timer++]=node;
    }
};



int main()
{
   


    return 0;
}
