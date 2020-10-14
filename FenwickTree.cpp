#include<bits/stdc++.h>
using namespace std;
#define ll long long
class FenwickTree
{
    //(one based indexing)
    // Refrence:- https://www.youtube.com/watch?v=CWDQJGaN1gY , cpalgorithms

    private:
    ll n;
    vector<ll> bit;
    public:
    FenwickTree(ll n)
    {
        this->n=n+1; 
        bit=vector<ll>(n+1,0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    /*--who is parent--*/
    /*
         find parent of 6(110)
         sol- flip right most set bit of 6(110) 
              that is (100)=>4
              so 4 is parent of 6...

        //FOR QUERIE//
         getparent = (orignal_no)-(orignal_no & 2's complement)
        //FOR UPDATE//
         getnext = (orignal_no)+(orignal_no&2's complement)
    */


    ll sum(ll ind)
    {
        int ret=0;
        //getparent = (orignal_no)-(orignal_no & 2's complement)
        for(ind++;ind>0;ind=ind-(ind&-ind))
        ret+=bit[ind];

        return ret;        
    }

    ll sum(ll l,ll r)
    {
        return sum(r)-sum(l-1);
    }

    void add(ll ind,int val)
    {
        //getnext = (orignal_no)+(orignal_no&2's complement)
        for(ind++;ind<n;ind=ind+(ind&-ind))
        bit[ind]+=val;
    }

};


int main()
{
    /*---PRACTICE QUESTIONS---*/
    
    //https://codeforces.com/problemset/problem/1430/E

    //


    return 0;
}
