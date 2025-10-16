/*

1. an acyclic graph will always be bipartite
2. a graph with even one odd length cycle present is not bipartite
3. means if cycles present and all are of even length, it will be bipartite
4. since we have divide exactly into 2 groups such that no edge is in the group
5. a and b are connected means they should be in the same group

*/


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
       // initially no node is assigned to a group
       vector<int> groups(graph.size(), -1);
    
        // the graph can be diconnected so loop over all vertices
       for(int node = 0; node < graph.size(); node++){

            // when the node is not grouped yet => new component
            if(groups[node] == -1){

                // if any component is not bipartite then whole graph is not bipartite
                if(checkBipartite(graph,node, groups) == false)
                    return false;
            }
       }

       return true;
    }

private:
    bool checkBipartite(vector<vector<int>>& graph, int node, vector<int>& groups){
        queue<pair<int,int>> q;

        // 0 with it's group
        q.push({node,0});
        groups[node] = 0;

        while(!q.empty()){
            const auto& [node,grp] = q.front();

            for(const auto& nbr: graph[node]){

                // when neighbour is not got any group
                // then assign a different group from current
                if(groups[nbr] == -1){
                    groups[nbr] = !grp;

                    // push the neighbour with it's group
                    q.push({nbr,groups[nbr]});
                }

                // when already assigned and the group and current group same
                // means there is an edge in same group => !bipartite
                else if(groups[nbr] == grp){
                    return false;
                }
            }

            q.pop();
        }

        return true;
    }
};