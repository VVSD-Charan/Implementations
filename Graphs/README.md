### Finding bridges (Critical connections) in graph
<li>A bridge / critical connection in a graph is an edge whose removal disconnects the graph or increases disconnected components.</li>
<li>We can find all bridges using DFS by using some data structures to identify bridges.</li>
<li>To identify bridges in graph , we use  : </li>
<ol>
    <li>A boolean <strong>visited</strong>array which keeps track of which nodes are visited.</li>
    <li>An integer <strong>inTime</strong> array which keeps track of the time at which a node was visited first time.</li>
    <li>An integer <strong>lowTime</strong> array which keeps track of least reach time adjacent vertices <strong> except parent vertex </strong></li>
</ol>
<li>If at any stage , the inTime of current node becomes lesser than lowTime of adjacent node , then it indicates that the edge between them is a bridge. This is because it means that the adjacent node has no way to reach other than current node. If there is a way then the lowTime of that node would have been lesser than or equal to insertion time of current node.</li>
<strong> Time complexity : O(V + E) => same as normal DFS </strong> <br>
<strong> Space complexity : O(3 * V) => Three vectors of size V for visited,lowTime and inTime </strong><br>

```
    int timer = 0;
    
    void getCriticalConnections(vector<int>adj[],vector<bool>&visited,vector<int>&inTime,vector<int>&lowTime,int src,int parent)
    {
        inTime[src] = lowTime[src] = timer++;
        visited[src] = true;
        
        for(auto it : adj[src])
        {
            if(!visited[it])
            {
                getCriticalConnections(adj,visited,inTime,lowTime,it,src,arr);
                lowTime[src] = min(lowTime[src],lowTime[it]);
                
                if(lowTime[it] > inTime[src])
                {
                    cout<<it<<" "<<src<<"\n";
                }
            }
            else if(it != parent)
            {
                lowTime[src] = min(lowTime[src],lowTime[it]);
            }
        }
    }
```


### Finding articulation points in graph

<li>An articulation point in a graph is a <strong>vertex</strong> whose removal disconnects the graph or increases disconnected components.</li>
<li>Critical connections / bridges are edges and articulation points are vertices.</li>
<li>The algorithm is almost similar to find bridges except for updating lowTimes for already visited nodes.</li>
<li>For finding articulation point , when we have a visited node as an adjacent node , we consider its <strong>inTime</strong> only instead of <strong>lowTime as we have done to find bridge</strong>. This is because here we are concerned only about vertices which are reachable by adjacent nodes so that upon removal of current node , we can decide if the adjacent node can reach top nodes or not.</li>
<strong> Time complexity : O(V + E) => same as normal DFS </strong> <br>
<strong> Space complexity : O(3 * V) => Three vectors of size V for visited,lowTime and inTime </strong><br>

```

int timer = 0;
    
    void dfs(vector<int>adj[],vector<bool>&visited,vector<int>&inTime,vector<int>&lowTime,vector<int>&articulation,int src,int parent)
    {
        inTime[src] = lowTime[src] = timer;
        visited[src] = true;
        timer++;
        
        int children = 0;
        
        for(auto it : adj[src])
        {
            if(it == parent)continue;
            
            if(!visited[it])
            {
                dfs(adj,visited,inTime,lowTime,articulation,it,src);
                lowTime[src] = min(lowTime[src],lowTime[it]);
                
                if(lowTime[it] >= inTime[src] && parent != -1)
                {
                    articulation[src]++;
                }
                children++;
            }
            else
            {
                lowTime[src] = min(lowTime[src],inTime[it]);
            }
        }
        
        if(children > 1 && parent == -1)
        {
            articulation[src]++;
        }
    }

```