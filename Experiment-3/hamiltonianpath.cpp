

class Solution {
public:

    vector<vector<int>> makeAdj(int total, vector<vector<int>> &edges) {
        vector<vector<int>> adj(total);
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        return adj;
    }

    bool goDfs(int curr, vector<vector<int>> &adj,
               vector<int> &visited, int cnt, int need) {

        if (cnt == need)
            return true;

        for (int next : adj[curr]) {
            if (visited[next] == 0) {
                visited[next] = 1;
                if (goDfs(next, adj, visited, cnt + 1, need))
                    return true;
                visited[next] = 0;
            }
        }
        return false;
    }

    bool check(int n, int m, vector<vector<int>> edges) {

        vector<vector<int>> adj = makeAdj(n + 1, edges);

        for (int i = 1; i <= n; i++) {
            vector<int> visited(n + 1, 0);
            visited[i] = 1;

            if (goDfs(i, adj, visited, 1, n))
                return true;
        }
        return false;
    }
};