
class Solution {
  public:
    void dfs(int u,vector<int> adj[],vector<bool> &vis,
    vector<int> &disc,vector<int> &low,vector<int> &parent,vector<bool> &isAP,
    int &time){
        
        vis[u] = true;
        disc[u] = low[u] = ++time;
        int children = 0;
        
        for(int v : adj[u]){
            if(!vis[v]){
                children++;
                parent[v] = u;
                dfs(v,adj,vis,disc,low,parent,isAP,time);
                low[u] = min(low[u],low[v]);
                
                if(parent[u]==-1 && children>1){
                    isAP[u] = true;
                }
                
                if(parent[u]!=-1 && low[v]>=disc[u]){
                    isAP[u] = true;
                }
            }else if(v!=parent[u]){
                low[u] = min(low[u],disc[v]);
            }
        }
        
    }
    
    
    
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> vis(V,false);
        vector<int> disc(V), low(V), parent(V,-1);
        vector<bool> isAP(V,false);
        
        int time = 0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,disc,low,parent,isAP,time);
            }
        }
        
        vector<int> result;
        for(int i=0;i<V;i++){
            if(isAP[i]) result.push_back(i);
        }
        if(result.empty()) return {-1};
        return result;
    }
};

