### Finding bridges in graph
<li>A bridge in a graph is an edge whose removal disconnects the graph or increases disconnected components.</li>
<li>We can find all bridges using DFS by using some data structures to identify bridges.</li>
<li>To identify bridges in graph , we use  : </li>
<ol>
    <li>A boolean <strong>visited</strong>array which keeps track of which nodes are visited.</li>
    <li>An integer <strong>inTime</strong> array which keeps track of the time at which a node was visited first time.</li>
    <li>An integer <strong>lowTime</strong> array which keeps track of least reach time adjacent vertices <strong> except parent vertex </strong></li>
</ol>
<li>If at any stage , the inTime of current node becomes lesser than lowTime of adjacent node , then it indicates that the edge between them is a bridge. This is because it means that the adjacent node has no way to reach other than current node. If there is a way then the lowTime of that node would have been lesser than or equal to insertion time of current node.</li>
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