// vvsdc
// Problem link : https://codeforces.com/gym/102694/problem/B

// Short  description
// Given a tree with n nodes. If an edge was added from node i to new node
// , what would the diameter of the created tree be?

// Intuition
// Get all diameter ends in the tree. If new node is added to a diameter end then
// Diameter increases by 1. Else it remains same 

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

ll maxDistNode,maxDistance;

void dfs(vector<ll>adj[],vector<ll>&maxDistances,ll src,ll parent,ll currDist)
{
    maxDistances[src]=max(maxDistances[src],currDist);

    if(maxDistance<currDist)
    {
        maxDistance=currDist;
        maxDistNode=src;
    }

    for(auto it:adj[src])
    {
        if(it!=parent)
        {
            dfs(adj,maxDistances,it,src,currDist+1);
        }
    }
}
 
void maxDistancesFromEachNodeToLeaf(vector<ll>adj[],vector<ll>&maxDistances)
{
    ll nodes=maxDistances.size()-1;

    //Pick a random node and get farthest node from it
    ll randomNode=1;
    maxDistNode=1;
    maxDistance=0;
    dfs(adj,maxDistances,randomNode,-1,0);

    //We have one end of diameter. Find farthest node from it to get another end
    ll firstEnd=maxDistNode;
    maxDistNode=firstEnd;
    maxDistance=0;
    dfs(adj,maxDistances,firstEnd,-1,0);

    //We have second end as well.Find maxDistances from each node to leaf
    ll secondEnd=maxDistNode;
    maxDistNode=secondEnd;
    maxDistance=0;
    dfs(adj,maxDistances,secondEnd,-1,0);
} 

void solve()
{
    ll nodes;   cin>>nodes;

    if(nodes==1)
    {
        cout<<"1\n";  return;
    }

    vector<ll>adj[nodes+1];

    for(ll i=0;i<nodes-1;i++)
    {
        int u,v;   cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll>maxDistances(nodes+1,0);
    maxDistancesFromEachNodeToLeaf(adj,maxDistances);

    ll diameter=*max_element(all(maxDistances));
    set<ll>diameterEnds;

    for(ll i=1;i<=nodes;i++)
    {
        if(maxDistances[i]==diameter)
        {
            diameterEnds.insert(i);
        }
    }

    vector<ll>dynamicDiameter(nodes+1);

    for(ll i=1;i<=nodes;i++)
    {
        if(diameterEnds.find(i)==diameterEnds.end())
        {
            dynamicDiameter[i]=diameter;
        }
        else 
        {
            dynamicDiameter[i]=diameter+1;
        }
    }

    for(ll i=1;i<=nodes;i++)
    {
        cout<<dynamicDiameter[i]<<"\n";
    }
}
 
signed main()
{
   speed;  
   
    solve();
}