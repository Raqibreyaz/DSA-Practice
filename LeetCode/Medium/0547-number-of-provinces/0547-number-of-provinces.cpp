/*

1. Loop over all the vertices
2. Apply DFS for every unvisited Province/Grouyp
3. on applying DFS on a group increase counter by 1

*/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>> graph;

        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[i].size(); j++)
                if (isConnected[i][j]) {
                    graph[i].push_back(j);
                }
        }

        int count = 0;
        vector<bool> visited(graph.size(),false);

        for(const auto& [node,_]: graph){
            if(DFS(graph,node,visited) > 0){
                count++;
            }
        }

        return count;
    }

private:
    int DFS(unordered_map<int,vector<int>>& graph,int node,vector<bool>& visited){
        if(visited[node])
            return 0;

        visited[node] = true;

        int count = 1;
        for(const auto& nbr: graph[node]){
            count += DFS(graph,nbr,visited);
        }

        return count;
    }
};