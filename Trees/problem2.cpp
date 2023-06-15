// Problem link : https://codeforces.com/contest/913/problem/B
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

bool dfs(vector<ll>adj[],ll src)
{
    bool ok=true;
    ll leaf_childen=0;

    for(auto it:adj[src])
    {
        if(adj[it].size()==0)
        {
            leaf_childen++;
        }
    }

    if(leaf_childen<3)
    {
        return false;
    }

    for(auto it:adj[src])
    {
        if(adj[it].size()>0)
        {
            ok=(ok&dfs(adj,it));
        }
    }

    return ok;
}


void solve()
{
   ll nodes;  cin>>nodes;
   vector<ll>adj[nodes+1];

   for(ll i=2;i<=nodes;i++)
   {
      ll node;   cin>>node;
      adj[node].push_back(i);
   }

   if(dfs(adj,1))
   {
       yes;  return;
   }

   no;
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