class Solution {
public: //T.C: O(n) and S.C:O(n)
    int answer = -1;
    void dfs(int node, vector<int>& edges,vector<bool>& vis,unordered_map<int,int>& dist ){
        vis[node]=true;
        int neighbour = edges[node];

        if(neighbour!=-1 && !vis[neighbour]){
            dist[neighbour]=dist[node]+1;
            dfs(neighbour,edges,vis,dist);
        }else if(neighbour!=-1 && dist.count(neighbour)){
            answer = max(answer,dist[node]-dist[neighbour]+1);
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n);
        for(int i=0;i<n;i++){
            unordered_map<int,int> dist;
            dist[i]=1;
            dfs(i,edges,vis,dist);
        }
        return answer;
    }
};