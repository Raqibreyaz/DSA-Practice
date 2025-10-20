/*

Approach 1: (DFS with Cycle Detection in Directed graph)
- loop over all the neighbours
- keep storing nodes states as "isCyclic", when any of it's neighbours isCyclic
node
- every node which leads to a terminal node is a 'safe node'
- total nodes - cyclic nodes = safe nodes

Approach 2: (Topological sort)
- we know that every node leading to a terminal node is a safe node
- means we are going from node to terminal node and there can be multiple
possibilities also
- what if we go from terminal node to nodes?
- using this way we can directly get terminal node!
- this will be combined with kahn's algo
- we have to reverse edges to traverse in reverse

        3   (3 to 0 and 4)
       / \
      0   4    (0,1,2 are in cycle)
     / \
    1-> 2 

=> only possible safe node = 4
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adj(graph.size());
        vector<int> inDegree(graph.size());

        // reverse all the edges
        for (int node = 0; node < graph.size(); node++) {
            for (const int& nbr : graph[node]) {
                adj[nbr].push_back(node);
                inDegree[node]++;
            }
        }

        queue<int> q;

        for (int node = 0; node < adj.size(); node++) {
            if (inDegree[node] == 0)
                q.push(node);
        }

        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();

            safeNodes.push_back(node);

            for (const int& nbr : adj[node]) {
                inDegree[nbr]--;

                if (inDegree[nbr] == 0)
                    q.push(nbr);
            }

            q.pop();
        }

        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};
