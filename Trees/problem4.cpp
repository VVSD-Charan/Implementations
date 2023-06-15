// Problem link : https://codeforces.com/contest/1593/problem/E
// vvsdc 

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

void solve()
{
   ll nodes,operations;  cin>>nodes>>operations;
   vector<ll>adj[nodes+1];

   if(nodes==1)
   {
      if(operations==0)
      {
        cout<<nodes<<"\n";
        return;
      }
      cout<<"0\n"; return;
   }

   vector<ll>degree(nodes+1,0);

   for(ll i=1;i<=nodes-1;i++)
   {
      ll u,v;  cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }

   //USing topo sort
   queue<ll>q;

   for(ll i=1;i<=nodes;i++)
   {
      degree[i]=adj[i].size();

      if(degree[i]==1)
      {
         q.push(i);
      }
   }

   ll removed=0;

   while(operations>0 && q.size()>0)
   {
       operations--;
       ll total=q.size();

       while(total--)
       {
          ll node=q.front();  q.pop();

          for(auto it:adj[node])
          {
            degree[it]--;
            if(degree[it]==1)
            {
                q.push(it);
            }
          }

          removed++;
       }
   }

   cout<<nodes-removed<<"\n";
}
 
signed main()
{
   speed;  
   ll t;   cin>>t;

   while(t--)
   {
      solve();
   }
}