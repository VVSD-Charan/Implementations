//vvsdc


// Intuition : 
// 1 => Pick any random node say x
// 2 => Find node at maximum distance from x and let it be y
// 3 => Find node at maximum distance from y and let it be z
// 4 => The nodes y and z are endpoints of diameter path and distance is diameter of tree

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define minpq priority_queue<ll,vector<ll>,greater<ll>>
#define speed ios :: sync_with_stdio(0); cin.tie(0); cout.tie(nullptr);
#define f first
#define s second
using namespace std;
ll mod=1e9+7;
 
void read_vec(vector<ll>&v)
{
    for(auto &it:v)
    {
        cin>>it;
    }
}
 
void print_vec(vector<ll>&arr)
{
    for(auto it:arr)
    {
        cout<<it<<" ";
    }
    cout<<"\n";
}
 
ll modInverse(ll A,ll M)
{
    for (ll X = 1; X < M; X++)
        if (((A % M) * (X % M)) % M == 1)
            return X;
}
 
bool isprime(ll n)
{
    
    if (n <= 1)
        return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
 
ll maxDist,maxDistNode;
 
void dfs(vector<ll>adj[],ll src,ll parent,ll distance)
{
    if(distance>maxDist)
    {
        maxDist=distance;
        maxDistNode=src;
    }
 
    for(auto it:adj[src])
    {
        if(it!=parent)
        {
            dfs(adj,it,src,distance+1);
        }
    }
}
 
void solve()
{
   ll nodes;   cin>>nodes;
   vector<ll>adj[nodes];
 
   for(ll i=1;i<=nodes-1;i++)
   {
      ll u,v;   cin>>u>>v;
      u--;
      v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   //Pick random node x
   ll x=0;
 
   maxDistNode=0;
   maxDist=0;
 
   //Find node at maximum distance from x
   dfs(adj,x,-1,0);
 
   ll y=maxDistNode;
 
   maxDistNode=y;
   maxDist=0;
 
   //Find node at maximum distance from y
   dfs(adj,y,-1,0);
 
   ll z=maxDistNode;
 
   //Distance y-z is diameter of tree and maxDist is diameter
   cout<<maxDist<<"\n";
   // cout<<y<<" "<<z<<"\n";
}
 
signed main()
{
   speed;  
   
    solve();
}