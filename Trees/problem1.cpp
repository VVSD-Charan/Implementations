// Problem link : https://codeforces.com/contest/115/problem/A
// vvsdc

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
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


ll bfs(vector<ll>adj[],ll src)
{
    queue<ll>q;   q.push(src);
    ll level=0;

    while(q.size())
    {
        ll nodes=q.size();
        level++;

        while(nodes--)
        {
            ll node=q.front();  q.pop();

            for(auto it:adj[node])
            {
                q.push(it);
            }
        }
    }

    return level;
}

void solve()
{
   ll nodes;   cin>>nodes;
   vector<ll>adj[nodes+1];
   vector<ll>parent(nodes+1,-1);

   for(ll i=1;i<=nodes;i++)
   {
      ll node;   cin>>node;
      if(node>0)
      {
        adj[node].push_back(i);
        parent[i]=node;
      }
   }

   ll max_level=0;

   for(ll i=1;i<=nodes;i++)
   {
      if(parent[i]==-1)
      {
         ll level=bfs(adj,i);
         max_level=max(level,max_level);
      }
   }

   cout<<max_level<<"\n";
}
 
signed main()
{
   speed;  
   // ll t;   cin>>t;

   // while(t--)
   // {
      solve();
   // }
}