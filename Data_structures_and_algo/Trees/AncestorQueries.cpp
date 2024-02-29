//vvsdc

// Problem statement
// Given a tree having n nodes (1 based indexing) rooted at 1 and q queries each having two inputs a and b. 
//Find if a is ancestor of b or not

//Constraints
// 1<= n <= 2*1e5
// 1<= q <= 2*1e5

// Intuition : 
// Performing dfs on each query results in TLE since it takes n*q operations ~ 4*1e10 .
// Better way is to use inTime and outTime in initial DFS traversal . 
// a is ancestor of b if  inTime[a] < inTime[b] < outTime[b] < outTime[a]
// We can solve each query in O(1) and initial DFS takes O(n) so overall Time complexity is O(n+q)
// Space complexity => O(n) recursion stack space for DFS + O(n) for inTime + O(n) for outTime => Overall ~ O(n) 


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

ll timer;

void dfs(vector<ll>adj[],ll src,vector<ll>&inTime,vector<ll>&outTime,ll parent)
{
    inTime[src]=timer++;

    for(auto it:adj[src])
    {
        if(it!=parent)
        {
            dfs(adj,it,inTime,outTime,src);
        }
    }

    outTime[src]=timer++;
}
 
void solve()
{
    timer=0;

   ll nodes,queries;   cin>>nodes>>queries;

   vector<ll>adj[nodes+1];

   for(int i=1;i<=nodes-1;i++)
   {
      ll u,v;   cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   vector<ll>inTime(nodes+1);
   vector<ll>outTime(nodes+1);

   ll root=1;
   dfs(adj,root,inTime,outTime,-1);

    //To query whether 1 is ancestor of 3 or not input it as {1 3}
   for(ll i=0;i<queries;i++)
   {
      ll u,v;   cin>>u>>v;

      if(inTime[u]<inTime[v] && inTime[v]<outTime[v] && outTime[v]<outTime[u])
      {
        //  yes;
        cout<<u<<" is an ancestor of "<<v<<"\n";
      }
      else
      {
        //  no;
        cout<<u<<" is NOT an ancestor of "<<v<<"\n";
      }
   }
}
 
signed main()
{
   speed;  
   
    solve();
}