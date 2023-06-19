//vvsdc
// Problem link : https://codeforces.com/problemset/problem/1363/C

//Intuition :
// If degree of special node x is <=1 then it is already 1 and the player
// Who takes first turn wins by removing it. 
// Else game continues till degree of x becomes 1. The next player wins
// So game happens till degree of x becomes 1 i.e all nodes except x and one neighbor of x remains
// Then immediate turn can remove x
// Players should remove total of n-2 nodes to remove x
// If n-2 is odd, then second player wins else first player

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
 
void solve()
{
    ll nodes,x;   cin>>nodes>>x;

    vector<ll>adj[nodes+1];
    vector<ll>degree(nodes+1,0);

    for(ll i=0;i<nodes-1;i++)
    {
        ll u,v;   cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    if(degree[x]<=1)
    {
        cout<<"Ayush\n";
        return;
    }

    if(nodes&1)
    {
        cout<<"Ashish\n";
        return;
    }

    cout<<"Ayush\n";
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