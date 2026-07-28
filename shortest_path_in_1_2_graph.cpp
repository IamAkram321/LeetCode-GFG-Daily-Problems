class Solution {
public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V + edges.size());

        int nxt = V;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];

            if (w == 1) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            } else {
                adj[u].push_back(nxt);
                adj[nxt].push_back(u);
                adj[nxt].push_back(v);
                adj[v].push_back(nxt);
                nxt++;
            }
        }

        vector<int> dist(nxt, -1);
        queue<int> q;

        q.push(src);
        dist[src] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist[dest];
    }
};