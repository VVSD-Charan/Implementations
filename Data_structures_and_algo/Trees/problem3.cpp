// Problem link : https://codeforces.com/contest/580/problem/C
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

ll dfs(vector<ll>adj[],vector<ll>&cats,ll src,ll parent,ll consecutive,ll m)
{
    if(consecutive>m){return 0;}
    if(adj[src].size()==1 && parent!=-1){return 1;}

    ll paths=0;
    for(auto it:adj[src])
    {
        if(it!=parent)
        {
            if(cats[it]==1)
            {
                paths+=dfs(adj,cats,it,src,consecutive+1,m);
            }
            else
            {
                paths+=dfs(adj,cats,it,src,0,m);
            }
        }
    }

    return paths;
}

void solve()
{
    ll nodes,m;   cin>>nodes>>m;
    vector<ll>cats(nodes+1);

    for(ll i=1;i<=nodes;i++)
    {
        ll cat;   cin>>cat;
        cats[i]=cat;
    }

    vector<ll>adj[nodes+1];

    for(ll i=1;i<=nodes-1;i++)
    {
        ll u,v;  cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll ans=dfs(adj,cats,1,-1,cats[1],m);

    cout<<ans<<"\n";
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