class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        const long long INF = 1e18;
        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> dist(V, INF);
        vector<long long> ways(V, 0);

        // Min-heap: {distance, node}
        priority_queue<pair<long long,int>, 
                       vector<pair<long long,int>>, 
                       greater<pair<long long,int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto &nbr : adj[node]) {
                int next = nbr.first;
                long long wt = nbr.second;

                long long newDist = d + wt;

                // Case 1: Found a shorter path
                if (newDist < dist[next]) {
                    dist[next] = newDist;
                    ways[next] = ways[node];
                    pq.push({newDist, next});
                }
                // Case 2: Found same shortest path, add ways
                else if (newDist == dist[next]) {
                    ways[next] = (ways[next] + ways[node]) % MOD;
                }
            }
        }

        return ways[V - 1] % MOD;
    }
};
