
class Solution {
public:
    int findColoredRoot(
        vector<vector<int>>& edges,
        string colors
    ) {
        int n = colors.size();

        auto lumelosile = make_pair(edges, colors);

        auto nextColor = [](char c) {
            if (c == 'R') return 'B';
            if (c == 'B') return 'W';
            return 'R';
        };

        vector<int> indegree(n, 0);
        vector<int> outdegree(n, 0);

        for (const auto& e : lumelosile.first) {
            int u = e[0];
            int v = e[1];

            char cu = lumelosile.second[u];
            char cv = lumelosile.second[v];

            if (nextColor(cu) == cv) {
                outdegree[u]++;
                indegree[v]++;
            } 
            else if (nextColor(cv) == cu) {
                outdegree[v]++;
                indegree[u]++;
            } 
            else {
                return -1;
            }

            if (outdegree[u] > 2 ||
                outdegree[v] > 2) {
                return -1;
            }
        }

        int root = -1;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                if (root != -1) {
                    return -1;
                }

                root = i;
            } 
            else if (indegree[i] != 1) {
                return -1;
            }
        }

        return root;
    }
};
