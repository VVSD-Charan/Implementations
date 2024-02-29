//vvsdc

//Question :
// determine for each node the maximum distance to another node.

//Intuition:
// The farthest node from every node will be an end point of diameter. 
// So all we have to do is to find both end points of diameter
// Then perform dfs to find maximum distance to each node from end points  

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

void dfs(vector<ll>adj[],vector<ll>&maxDistance,ll src,ll parent,ll currDist)
{
    maxDistance[src]=max(maxDistance[src],currDist);

    if(currDist > maxDist){
        maxDist=currDist;
        maxDistNode=src;
    }

    for(auto it:adj[src]){
        if(it!=parent){
            dfs(adj,maxDistance,it,src,currDist+1);
        }
    }
}

pair<int,int> DiameterEnds(vector<ll>adj[],vector<ll>&maxDistance)
{
    //Picking a random node
    ll randomNode=1;

    //To obtain first end point
    maxDistNode=1;
    maxDist=0;
    dfs(adj,maxDistance,randomNode,-1,0);

    ll firstEnd=maxDistNode;

    //To obtain second end point
    maxDistNode=firstEnd;
    maxDist=0;
    dfs(adj,maxDistance,firstEnd,-1,0);

    ll secondEnd=maxDistNode;

    //To obtain max distances from second end as well
    dfs(adj,maxDistance,secondEnd,-1,0);

    return {firstEnd,secondEnd};
}
 
void solve()
{
   ll nodes;  cin>>nodes;
   vector<ll>adj[nodes+1];

   for(ll i=0;i<nodes-1;i++)
   {
      ll u,v;   cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   vector<ll>maxDistance(nodes+1,0);

   pair<int,int>diameterEndPoints = DiameterEnds(adj,maxDistance);

   for(ll i=1;i<=nodes;i++)
   {
      cout<<maxDistance[i]<<" ";
   }
   cout<<"\n";
}
 
signed main()
{
   speed;  
   
    solve();
}